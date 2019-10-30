`include "global_def.v"

module flipflop #(
  parameter WIDTH = 32
) ( 
   input         clk,
   input         rst,
   input         wr,
   input   [WIDTH-1:0]  d,
   output reg [WIDTH-1:0]  q
);
   
   always @(posedge clk) begin
      if (rst) begin
        q<=0;
      end else if (wr) begin
        q<=d;
      end
   end // end always
   
endmodule


