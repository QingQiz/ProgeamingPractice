// Note: combitional logic

`include "ctrl_encode_def.v"
module alu(a, b, aluop, c, compare);
           
   input  signed [31:0] a, b;
   input  signed [4:0]  aluop;
   output signed [31:0] c;
   output 				compare;
   
   reg [31:0] c;
   integer    i;
       
   always @( * ) begin
      case ( aluop )
          `ALUOp_NOP:  c = b;                        // NOP
		      `ALUOp_ADD:  c = a + b;                    // ADD
          `ALUOp_ADDU: c = a + b;                    // ADDU
		      `ALUOp_SUB:  c = a - b;                    // SUB
          `ALUOp_SUBU: c = a - b;                    // SUBU
          `ALUOp_AND:  c = a & b;                    // AND/ANDI
          `ALUOp_OR:   c = a | b;                    // OR/ORI
          `ALUOp_XOR:  c = a ^ b;                    // XOR/XORI
		      `ALUOp_NOR:  c = ~(a | b);                 // NOR
          `ALUOp_SLL:  c = (b << a[4:0]);            // SLL/SLLV
          `ALUOp_SRL:  c = (b >> a[4:0]);	           // SRL/SRLV
          `ALUOp_SLT:  c = (a < b) ? 32'd1 : 32'd0;  // SLT/SLTI
          `ALUOp_SLTU: c = ({1'b0, a} < {1'b0, b}) ? 32'd1 : 32'd0; // SLTU/SLTIU         
          `ALUOp_EQL:  c = (a == b) ? 32'd1 : 32'd0; // EQUAL
          `ALUOp_BNE:  c = (a != b) ? 32'd1 : 32'd0; // NOT EQUAL
          `ALUOp_GT0:  c = (a >  0) ? 32'd1 : 32'd0; // Great than 0
          `ALUOp_GE0:  c = (a >= 0) ? 32'd1 : 32'd0; // Great than & equal 0
          `ALUOp_LT0:  c = (a <  0) ? 32'd1 : 32'd0; // Less than 0
          `ALUOp_LE0:  c = (a <= 0) ? 32'd1 : 32'd0; // Less than & equal 0
          default:   c = 32'd0;                	     // Undefined operation
      endcase
   end // end always
   
   assign compare = c[0];

endmodule
    
