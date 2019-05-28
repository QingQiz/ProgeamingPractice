// top module of MIPS

`include "./ctrl_encode_def.v"
`include "./instruction_def.v"

module mips (
             // clock and reset
             input         clk ,
             input         rst ,
             // instruction interface
             output [31:0] imem_addr,
             input [31:0]  imem_dout,
             // data memory interface
             output [31:0] dmem_addr,
             output [31:0] dmem_din ,
             output [ 3:0] dmem_be ,
             output        dmem_wren,
             input [31:0]  dmem_dout
             );

   ///////////////****************************///////////////////////

   // Register file connection
   wire [ 4:0]             write_register, read_register1, read_register2;
   wire [31:0]             rf_write_data, rf_read_data1, rf_read_data2;
   wire                    regwrite      ;

   regfile U_RF (
                 .clk  (clk           ),
                 .rst  (rst           ),
                 .rw   (write_register),
                 .ra   (read_register1),
                 .rb   (read_register2),
                 .busa (rf_read_data1 ),
                 .busb (rf_read_data2 ),
                 .busw (rf_write_data ),
                 .regwr(regwrite      )
                 );

   ///////////////****************************///////////////////////

   // ALU connection
   wire [31:0]             alu_a, alu_b, alu_c;
   wire [ 4:0]             alu_op;
   wire                    zero  ;

   alu U_ALU (.a(alu_a), .b(alu_b), .c(alu_c), .aluop(alu_op), .compare(zero));


   // All pipe line stage registers define

   ///////////////****************************///////////////////////
   // IF: Fetch stage
   wire                    pcsrc  ;
   wire [31:0]             pc     ; // pc register
   wire [31:0]             pc_w   ; // pc wire used in flipflop in data in
   wire [31:0]             if_pc  ; // pc register in IF/ID pipeline register
   wire [31:0]             if_pc_w;
   wire [31:0]             if_ir  ; // instruction register

   ///////////////****************************///////////////////////
   // ID: Decode stage
   wire [31:0]             id_pc        ; // copy from if_pc
   wire [31:0]             id_imm32     ;
   wire [31:0]             id_imm32_w   ;
   wire [ 4:0]             id_ex_aluop  ;
   wire [ 4:0]             id_ex_aluop_w;
   wire [ 4:0]             id_write_register_w;
   wire [ 4:0]             id_write_register;

   ///////////////****************************///////////////////////
   // Decode signals
   wire [ 5:0]             opcode;
   wire [ 5:0]             func  ;
   wire [ 4:0]             rs    ;
   wire [ 4:0]             rt    ;
   wire [ 4:0]             rd    ;
   wire [15:0]             imm16 ;

   ///////////////****************************///////////////////////
   // EX: Execute state
   wire [31:0]             ex_aluout          ;
   wire [31:0]             ex_add_result      ;
   wire [31:0]             ex_add_result_w    ;
   wire [ 4:0]             ex_write_register  ;
   wire [ 4:0]             ex_write_register_w;
   wire [31:0]             ex_read_data2      ;

   ///////////////****************************///////////////////////
   // MEM: Memory state
   wire [31:0]             mem_readdata      ;
   wire [31:0]             mem_aluout        ;
   wire [ 4:0]             mem_write_register;

   ///////////////****************************///////////////////////
   // WB: Write back state
   // No register, write back into register files.

   // Data and control path
   ///////////////****************************///////////////////////
   // IF: Fetch stage
   // Read instruction
   assign imem_addr = pc;
   assign pc_w = pcsrc ? ex_add_result:(pc+4);
   assign if_pc_w = pc + 4;
   flipflop #(32) u_if_ir (clk,rst,1'b1,imem_dout,if_ir);
   flipflop #(32) u_pc (clk,rst,1'b1,pc_w,pc);
   flipflop #(32) u_if_pc (clk,rst,1'b1,if_pc_w,if_pc);

   ///////////////****************************///////////////////////
   // ID: Decode stage
   // instruction format decoding
   assign opcode    = if_ir[31:26];
   assign func      = if_ir[5:0];
   assign rs        = if_ir[25:21];
   assign rt        = if_ir[20:16];
   assign rd        = if_ir[15:11];
   assign imm16     = if_ir[15:0];
   assign inst_ori  = (opcode==`INSTR_ORI_OP);
   assign inst_addu = (opcode==`INSTR_RTYPE_OP) && (func==`INSTR_ADDU_FUNCT);
   assign inst_subu = (opcode==`INSTR_RTYPE_OP) && (func==`INSTR_SUBU_FUNCT);
   assign inst_j    = (opcode==`INSTR_J_OP);
   assign inst_lw   = (opcode==`INSTR_LW_OP);
   assign inst_sw   = (opcode==`INSTR_SW_OP);
   assign inst_beq  = (opcode==`INSTR_BEQ_OP);
   assign id_imm32_w = inst_ori ?{{16{1'b0}}, imm16} : {{16{imm16[15]}}, imm16};
   assign read_register1 = rs;
   assign read_register2 = rt;
   assign id_ex_regdst_w = (opcode==`INSTR_RTYPE_OP);
   assign id_ex_alusrc_w = inst_lw | inst_sw | inst_ori;
   assign id_ex_aluop_w = inst_ori ? `ALUOp_OR : (inst_subu ? `ALUOp_SUBU : `ALUOp_ADDU);
   assign id_mem_memread_w = inst_lw;
   assign id_wb_regwr_w = (opcode==`INSTR_RTYPE_OP)| inst_lw | inst_ori;
   assign id_write_register_w = id_ex_regdst_w ? rd : rt;
   flipflop #(32) u_id_imm32 (clk,rst,1'b1,id_imm32_w,id_imm32);
   flipflop #(1) u_id_ex_regdst (clk,rst,1'b1,id_ex_regdst_w,id_ex_regdst);
   flipflop #(1) u_id_ex_alusrc (clk,rst,1'b1,id_ex_alusrc_w,id_ex_alusrc);
   flipflop #(5) u_id_ex_aluop (clk,rst,1'b1,id_ex_aluop_w,id_ex_aluop);
   flipflop #(1) u_id_mem_memread (clk,rst,1'b1,id_mem_memread_w,id_mem_memread);
   flipflop #(5) u_id_write_register (clk,rst,1'b1,id_write_register_w,id_write_register);
   flipflop #(1) u_id_wb_regwr (clk,rst,1'b1,id_wb_regwr_w,id_wb_regwr);
   flipflop #(1) u_id_inst_beq (clk,rst,1'b1,inst_beq,id_inst_beq);
   flipflop #(1) u_id_memtoreg (clk,rst,1'b1,inst_lw,id_memtoreg);
   flipflop #(32) u_id_pc (clk,rst,1'b1,if_pc,id_pc);
   ///////////////****************************///////////////////////
   // EXE stage
   assign alu_a  = rf_read_data1;
   assign alu_b  = id_ex_alusrc ? id_imm32:rf_read_data2;
   assign alu_op = id_ex_aluop;
   assign ex_add_result_w = id_pc + (id_imm32<<2);
   assign ex_write_register_w = id_write_register;
   flipflop #(32) u_ex_aluout (clk,rst,1'b1,alu_c,ex_aluout);
   flipflop #(1) u_ex_zero (clk,rst,1'b1,zero,ex_zero);
   flipflop #(32) u_ex_add_result (clk,rst,1'b1,ex_add_result_w,ex_add_result);
   flipflop #(5) u_ex_write_register (clk,rst,1'b1,ex_write_register_w,ex_write_register);
   flipflop #(1) u_ex_mem_memread (clk,rst,1'b1,id_mem_memread,ex_mem_memread);
   flipflop #(1) u_ex_wb_regwr (clk,rst,1'b1,id_wb_regwr,ex_wb_regwr);
   flipflop #(32) u_ex_read_data2 (clk,rst,1'b1,rf_read_data2,ex_read_data2);
   flipflop #(1) u_ex_inst_beq (clk,rst,1'b1,id_inst_beq,ex_inst_beq);
   flipflop #(1) u_ex_memtoreg (clk,rst,1'b1,id_memtoreg,ex_memtoreg);

   ///////////////****************************///////////////////////
   // MEM stage
   assign pcsrc = ex_zero & ex_inst_beq;
   assign dmem_din  = ex_read_data2;
   assign dmem_addr = ex_aluout;
   assign dmem_be   = 4'b1111;
   assign dmem_wren = !ex_mem_memread;
   flipflop #(32) u_mem_readdata (clk,rst,1'b1,dmem_dout,mem_readdata);
   flipflop #(5) u_mem_write_register (clk,rst,1'b1,ex_write_register,mem_write_register);
   flipflop #(1) u_mem_wb_regwr (clk,rst,1'b1,ex_wb_regwr,mem_wb_regwr);
   flipflop #(32) u_mem_aluout (clk,rst,1'b1,ex_aluout,mem_aluout);
   flipflop #(1) u_mem_memtoreg (clk,rst,1'b1,ex_memtoreg,mem_memtoreg);

   ///////////////****************************///////////////////////
   // Write back stage
   assign write_register = mem_write_register;
   assign rf_write_data  = mem_memtoreg ? mem_readdata:mem_aluout;
   assign regwrite       = mem_wb_regwr;
endmodule
