`include "global_def.v"
module regfile( clk, rst, ra, rb, rw, busa, busb, busw, regwr);
    
   input         clk;
   input         rst;
   input  [4:0]  ra, rb, rw;
   input  [31:0] busw;
   output reg [31:0] busa, busb;
   input         regwr;
   
   reg [31:0] rf[31:0];
   
   integer i;
   
   always @(posedge clk) begin
      if (rst) begin
       for (i=0; i<32; i=i+1)
         rf[i] <= 0;
      end else if (regwr) begin
         // DON'T write $zero
         if (rw!=0)
            rf[rw] <= busw;
      end
   end // end always
   always @(posedge clk) begin
      if (rst) begin
        busa <= 0;
        busb <= 0;
      end else begin
        busa <= (ra == 0) ? 32'd0 : rf[ra];
        busb <= (rb == 0) ? 32'd0 : rf[rb];
      end
   end // end always
   
endmodule


