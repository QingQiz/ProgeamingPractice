module a2a2 (/*AUTOARG*/
   // Outputs
   s, c,
   // Inputs
   x, y, c0
   ) ;
   input [1:0] x, y;
   input       c0;
   output [1:0] s;
   output       c;

   reg          c;
   reg          c1;
   reg          s;


   always @ ( /*AUTOSENSE*/c0 or x or y) begin
      c1 = (x[0] & y[0]) | (x[0] & c0) | (y[0] & c0);
      {c, s} = {(x[1] & y[1]) | (x[1] & c1) | (y[1] & c1), x[1] ^ y[1] ^ c1, x[0] ^ y[0] ^ c0};
   end

endmodule // a2a2
