module swi21 (/*AUTOARG*/
   // Outputs
   f,
   // Inputs
   x0, x1, m
   ) ;
   input x0, x1, m;
   output f;

   assign f = (~m & x0) | (m & x1);
endmodule // swi21
