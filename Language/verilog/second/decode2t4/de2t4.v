module de2t4 (/*AUTOARG*/
   // Outputs
   de,
   // Inputs
   code
   ) ;
   input [1:0] code;
   output [3:0] de;
   reg          de;



   always @(code)
     case (code)
       2'b00: begin
          assign de = 4'b0001;
       end
       2'b01: begin
          assign de = 4'b0010;
       end
       2'b10: begin
          assign de = 4'b0100;
       end
       2'b11: begin
          assign de = 4'b1000;
       end
     endcase // case (code)

endmodule // de2t4
