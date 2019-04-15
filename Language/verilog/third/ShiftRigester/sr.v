module sr (/*AUTOARG*/
   // Outputs
   q,
   // Inputs
   in, clk
   ) ;
   input l, clk;
   output reg [3:0] q;

   always @ (posedge clk) begin
       if (l)
           q <= r;
       else begin
           q[1] <= q[0];
           q[2] <= q[1];
           q[3] <= q[2];
       end
   end

endmodule // sr
