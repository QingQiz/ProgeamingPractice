// top module of MIPS

`include "ctrl_encode_def.v"
`include "instruction_def.v"

module mips( clk, rst, mem_waddr, mem_raddr, mem_din, mem_wren, mem_dout);
   // clock and reset
   input   clk;
   input   rst;

   // code and data mixed memory interface
   output  wire [31:0] mem_waddr, mem_raddr;
   output [31:0]       mem_din;
   output  reg         mem_wren;
   input [31:0]        mem_dout;

   // decode signals
   wire [5:0]          opcode;
   wire [5:0]          func;
   wire [4:0]          rs;
   wire [4:0]          rt;
   wire [4:0]          rd;
   wire [15:0]         imm16;
   wire [25:0]         imm26;
   reg [31:0]          imm32;

   // regfile connection
   wire [4:0]          rw;
   wire [31:0]         busw;
   wire [31:0]         busa, busb;
   reg                 regwr;

   // ALU connection
   wire [31:0]         alu_a;
   reg [31:0]          alu_b;
   wire [31:0]         alu_c;
   reg [ 4:0]          aluop;
   wire                zero;

   regfile U_RF (
                 .clk(clk), .rst(rst), .rw(rw), .ra(rs), .rb(rt),
                 .busa(busa), .busb(busb), .busw(busw), .regwr(regwr)
                 );

   alu U_ALU (
              .a(alu_a), .b(alu_b), .c(alu_c), .aluop(aluop), .compare(zero)
              );


   // All registers except RF in multi cycle MIPS
   reg [31:0]          pc;
   reg [31:0]          ir; // instruction reg
   reg [31:0]          aluout;

   // All Control Point
   reg                 pcsel;
   reg                 irwr, pcwr, pcwrcond, iord;
   reg                 regdst, alusela, memtoreg, extop;
   reg [1:0]           aluselb;

   // FSM state define
   parameter
     FETCH = 4'd0,
     DECODE = 4'd1,
     RTYPE = 4'd2,
     ORI = 4'd3,
     LW = 4'd4,
     SW = 4'd5,
     BEQ = 4'd6,
     J = 4'd7,
     RWRITE = 4'd8,      // R type ins write back register files
     ORIWRITE = 4'd9,    // ORi type ins write back register files
     LWREADMEM = 4'd10,  // LW type ins read data memory
     LWWRITE = 4'd11,    // LW type ins write back register files
     SWWRITE = 4'd12,    // SW type ins write back register files
     BEQCOMPARE = 4'd13,
     BEQWRITE = 4'd14;
   reg [3:0]           state, nstate;

   // Data path
   assign opcode = ir[31:26];
   assign func = ir[5:0];
   assign rs = ir[25:21];
   assign rt = ir[20:16];
   assign rd = ir[15:11];
   assign imm16 = ir[15:0];
   assign imm26 = ir[25:0];

   // PC register
   always @(posedge clk) begin
      if (rst)
        pc<=32'b0;
      else begin
         if (pcwr|(pcwrcond&zero))
           if (pcsel)
             pc<={pc[31:28],imm26,2'b0};
           else
             pc<=alu_c;
      end
   end

   // Instruction register
   always @(posedge clk) begin
      if (rst)
        ir<=32'b0;
      else if (irwr)
        ir<=mem_dout;
   end

   // ALU out register
   always @(posedge clk) begin
      if (rst)
        aluout<=32'b0;
      else
        aluout<=alu_c;
   end

   // Extender
   always @(*) begin
      imm32 = {{16{imm16[15]}}, imm16};
      if (extop==1)
        imm32 = {{16{1'b0}}, imm16};
   end

   // ALL MUX here
   assign rw = regdst ? rd: rt;
   assign busw = memtoreg ? mem_dout:aluout;
   assign alu_a = alusela ? busa:pc;
   assign mem_raddr = iord ? aluout:pc;
   assign mem_waddr = aluout;
   assign mem_din = busb;

   // ALU sel b: mux4
   always @(*) begin
      case (aluselb)
        0: alu_b = 4;
        1: alu_b = busb;
        2: alu_b = imm32<<2;
        3: alu_b = imm32;
      endcase
   end

   // state control
   always @(posedge clk) begin
      if (rst)
        state<=FETCH;
      else
        state<=nstate;
   end

   always @(*) begin
      nstate = state;
      case(state)
        FETCH: nstate=DECODE;
        DECODE: begin
           case(opcode)
             `INSTR_RTYPE_OP: nstate=RTYPE;
             `INSTR_ORI_OP:  nstate=ORI;
             `INSTR_LW_OP:  nstate=LW;
             `INSTR_SW_OP:  nstate=SW;
             `INSTR_BEQ_OP:  nstate=BEQ;
             `INSTR_JAL_OP:  nstate=J;
           endcase
        end
        RTYPE:  nstate=RWRITE;
        ORI:    nstate=ORIWRITE;
        //LW:     nstate=LWREADMEM;
        LW:     nstate=LWWRITE;
        //LWREADMEM:  nstate=LWWRITE;
        SW:  nstate=SWWRITE;
        BEQ: nstate=BEQCOMPARE;
        BEQCOMPARE: nstate=BEQWRITE;
        default:  nstate=FETCH; // all last cycle will jump to fetch
      endcase
   end // end always

   // All control signals
   always @(*) begin
      // set the default value into zero
      pcwr = 0;
      pcwrcond = 0;
      iord = 0;
      mem_wren = 0;
      irwr = 0;
      regdst = 0;
      regwr = 0;
      alusela =0;
      extop = 0;
      memtoreg = 0;
      aluselb =0;
      pcsel = 0;
      aluop = `ALUOp_NOP;
      // only non default is set in the following:
      case(state)
        FETCH: begin
           irwr = 1;
        end
        RTYPE: begin
           case (func)
             `INSTR_ADDU_FUNCT: aluop = `ALUOp_ADDU;
             `INSTR_SUBU_FUNCT: aluop = `ALUOp_SUBU;
             default:aluop = `ALUOp_ADDU;
           endcase
           regdst = 1;
           alusela = 1;
           aluselb = `ALUSelB_FrombusB;
        end
        RWRITE: begin
           regwr = 1;
           memtoreg = 0;
           regdst =1;

           aluop = `ALUOp_ADDU;
           alusela = 0;
           aluselb = `ALUSelB_4;
           pcwr = 1;
        end
        ORI: begin
           aluop = `ALUOp_OR;
           alusela = 1;
           aluselb = 3;
        end
        ORIWRITE:begin
           // Write dst register
           regwr = 1;
           memtoreg = 0;
           regdst = 0;
           // pc+4
           aluop =`ALUOp_ADDU;
           alusela = 0;
           aluselb = `ALUSelB_4;
           pcwr = 1;
        end
        SW: begin
           aluop =`ALUOp_ADDU;
           alusela = 1;
           aluselb = 3;
        end
        LW: begin
           aluop =`ALUOp_ADDU;
           alusela = 1;
           aluselb = 3;
        end
        LWREADMEM: begin
           // read memory
           aluop =`ALUOp_ADDU;
           alusela = 1;
           aluselb = 3;
        end
        LWWRITE: begin
           // write dst register
           iord = 1;
           memtoreg = 1;
           regwr = 1;
           // pc+4
           aluop =`ALUOp_ADDU;
           alusela = 0;
           aluselb = `ALUSelB_4;
           pcwr = 1;
        end
        SWWRITE: begin
           // write memory
           mem_wren = 1;
           iord = 1;
           // pc+4
           aluop =`ALUOp_ADDU;
           alusela = 0;
           aluselb = `ALUSelB_4;
           pcwr = 1;
        end
        BEQ: begin
            // pc + 4
            aluop = `ALUOp_ADDU;
            alusela = 0;
            aluselb = 0;
            pcwr = 1;
        end
        BEQCOMPARE: begin
            aluop = `ALUOp_SUBU;
            alusela = 1;
            aluselb = 1;
        end
        BEQWRITE: begin
            // pc + imm
            aluop = `ALUOp_ADDU;
            alusela = 0;
            aluselb = 2;
            //pcwr = 1;
            pcwrcond = 1;
        end
        J: begin
            pcsel = 1;
            pcwr = 1;
        end
        default: begin
        end
      endcase
   end

endmodule
