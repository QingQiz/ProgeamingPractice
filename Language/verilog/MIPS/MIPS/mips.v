// top module of MIPS

`include "ctrl_encode_def.v"
`include "instruction_def.v"

module mips( clk, rst, imem_addr, imem_dout, dmem_addr, dmem_din, dmem_be, dmem_wren, dmem_dout );
   // clock and reset
   input   clk;
   input   rst;

   // instruction interface
   output [31:0] imem_addr;
   input [31:0]  imem_dout;

   // data memory interface
   output [31:0] dmem_addr;
   output [31:0] dmem_din;
   output [3:0]  dmem_be;
   output        dmem_wren;
   input [31:0]  dmem_dout;

   // decode signals
   wire [5:0]    opcode;
   wire [5:0]    func;
   wire [4:0]    rs;
   wire [4:0]    rt;
   wire [4:0]    rd;
   wire [15:0]   imm16;
   wire [25:0]   imm26;
   reg [31:0]    imm32;

   // regfile connection
   wire [4:0]    rw;
   wire [31:0]   busw;
   wire [31:0]   busa, busb;
   reg           regwr;

   // ALU connection
   wire [31:0]   alu_b;
   reg [4:0]     aluctr;
   wire [31:0]   aluout;
   wire          compare;


   regfile U_RF (
                 .clk(clk), .rst(rst), .rw(rw), .ra(rs), .rb(rt),
                 .busa(busa), .busb(busb), .busw(busw), .regwr(regwr)
                 );

   alu U_ALU (
              .a(busa), .b(alu_b), .c(aluout), .aluop(aluctr), .compare(compare)
              );


   // Only one register in single cycle MIPS
   reg [31:0]    pc;

   // Other Control Point
   reg           regdst;
   reg [1:0]     extop;
   reg           alusrc;
   reg           memwr;
   reg           memtoreg;


   // Data path
   assign opcode = imem_dout[31:26];
   assign func = imem_dout[5:0];
   assign rs = imem_dout[25:21];
   assign rt = imem_dout[20:16];
   assign rd = imem_dout[15:11];
   assign imm16 = imem_dout[15:0];
   assign imm26 = imem_dout[25:0];
   assign dmem_addr = aluout;
   assign dmem_din = busb;
   assign imem_addr = pc;
   assign dmem_wren = memwr;
   assign dmem_be = 4'b1111;

   // PC
   always @(posedge clk) begin
      if (rst)
        pc<=32'b0;
      else begin
         pc<=pc+4;
         if ((opcode==`INSTR_BEQ_OP)&&(compare==1'b1))
           pc<=pc+4+(imm32 << 2);
         if (opcode==`INSTR_J_OP)
           pc<={pc[31:28],imm26,2'b00};
      end
   end // end always

   // Extender
   always @(*) begin
      imm32 <= {{16{imm16[15]}}, imm16};
      if (opcode==`INSTR_ORI_OP)
        imm32 <= {{16{1'b0}}, imm16};
   end

   // all MUX here
   assign alu_b = alusrc ? imm32:busb;
   assign rw = regdst ? rd: rt;
   assign busw = memtoreg ? dmem_dout:aluout;


   always @(*) begin
      // set default value
      {regwr, regdst, extop, alusrc, aluctr, memwr, memtoreg}={1'b0, 1'b0, `EXT_SIGNED, 1'b0, `ALUOp_ADDU, 1'b0, 1'b0};
      case(opcode)
        `INSTR_RTYPE_OP: begin
           case (func)
             `INSTR_ADDU_FUNCT: {regwr, regdst, extop, alusrc, aluctr, memwr, memtoreg}={1'b1, 1'b1, `EXT_SIGNED, 1'b0, `ALUOp_ADDU, 1'b0, 1'b0};

             `INSTR_SUBU_FUNCT: {regwr, regdst, extop, alusrc, aluctr, memwr, memtoreg}={1'b1, 1'b1, `EXT_SIGNED, 1'b0, `ALUOp_SUBU, 1'b0, 1'b0};
           endcase
        end
        `INSTR_ORI_OP: {regwr, regdst, extop, alusrc, aluctr, memwr, memtoreg}={1'b1, 1'b0, `EXT_SIGNED, 1'b1, `ALUOp_OR, 1'b0, 1'b0};
        `INSTR_LW_OP:  {regwr, regdst, extop, alusrc, aluctr, memwr, memtoreg}={1'b1, 1'b0, `EXT_SIGNED, 1'b1, `ALUOp_ADD, 1'b0, 1'b1};
        `INSTR_SW_OP:  {regwr, regdst, extop, alusrc, aluctr, memwr, memtoreg}={1'b0, 1'b0, `EXT_SIGNED, 1'b1, `ALUOp_ADD, 1'b1, 1'b0};
        `INSTR_BEQ_OP: {regwr, regdst, extop, alusrc, aluctr, memwr, memtoreg}={1'b0, 1'b0, `EXT_SIGNED, 1'b0, `ALUOp_EQL, 1'b0, 1'b0};
        `INSTR_J_OP:   {regwr, regdst, extop, alusrc, aluctr, memwr, memtoreg}={1'b1, 1'b1, `EXT_SIGNED, 1'b1, `ALUOp_ADDU, 1'b1, 1'b1};
      endcase
   end // end always

endmodule
