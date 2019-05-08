// Data memory model
// Write operate: write data din with address addr on posedge clk
// Read  operate: read out address addr immediately without clock for supporint Single Cycle MIPS.

module dmem( clk, addr, din, be, wren, dout );

   input         clk;
   input [11:2]  addr;
   input [31:0]  din;
   input [3:0]   be;	// byte enable used for sh/sb/sw instructions
   input         wren;
   output [31:0] dout;

   reg [31:0]    dmem[1023:0];

   always @(posedge clk) begin
      if (wren) begin
         dmem[addr] <= din;
      end
   end // end always

   assign dout = dmem[addr];

   // You should write the dmem initial data into dmem.txt in advance.
   initial begin
      $readmemb( "../src/dmem.txt" , dmem) ;
   end

endmodule
