module en8t3 (/*AUTOARG*/
   // Outputs
   out,
   // Inputs
   in
   ) ;
   input  [7:0] in;
   output [2:0] out;

   reg          out;


   always @(in)
     casex (in)
       8'b1xxxxxxx: begin
          assign out = 3'b111;
       end
       8'b01xxxxxx: begin
          assign out = 3'b110;
       end
       8'b001xxxxx: begin
          assign out = 3'b101;
       end
       8'b0001xxxx: begin
          assign out = 3'b100;
       end
       8'b00001xxx: begin
          assign out = 3'b011;
       end
       8'b000001xx: begin
          assign out = 3'b010;
       end
       8'b0000001x: begin
          assign out = 3'b001;
       end
       8'b00000001: begin
          assign out = 3'b000;
       end
     endcase // casex (in)

endmodule // en8t3
