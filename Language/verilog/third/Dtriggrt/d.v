module d (/*AUTOARG*/
   // Outputs
   q, nq,
   // Inputs
   d, clock
   ) ;
   input d, clock;
   output q, nq;

   reg    q, nq;


   always @ (posedge clock) begin
      q = d ? 1 : 0;
      nq = ~q;
   end

endmodule // d
