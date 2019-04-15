module counter (/*AUTOARG*/
   // Outputs
   q,
   // Inputs
   clock, reset
   ) ;
   input clock, reset;
   output [3:0] q;

   reg    q;

   always @(posedge clock) begin
      if (reset == 1) q <= 4'b0000;
      q[0] <= ~q[0];
      if (q[0] == 1) q[1] <= ~q[1];
      if (q[1] & q[0] == 1) q[2] <= ~q[2];
      if (q[0] & q[1] & q[2] == 1) q[3] <= ~q[3];
   end

endmodule // counter
