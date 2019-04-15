module Tr (/*AUTOARG*/
   // Outputs
   led, q,
   // Inputs
   res, clk, e
   ) ;
   input  res, clk, e;
   output led;
   output [4:0] q;

   reg          led, q;

   always @ (negedge res, posedge clk) begin
      if (!res) begin
         q <= 0;
         led <= 0;
      end
      else if (e) begin
         q <= q + 1;
         if (q == 5'b10100)
           led = ~led;
      end
   end

endmodule // Tr
