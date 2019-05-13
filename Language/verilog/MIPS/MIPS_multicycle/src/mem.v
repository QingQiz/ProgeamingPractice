// Data memory model
// Write operate: write data din with address addr on posedge clk
// Read  operate: read out address addr immediately without clock for supporint Single Cycle MIPS.

module mem( clk, waddr, raddr, din, wren, dout);

   input         clk;
   input  [11:2] waddr;
   input  [11:2] raddr;
   input  [31:0] din;
   input         wren;
   output wire [31:0] dout;

   reg [31:0] mem[2047:0];

   always @(posedge clk) begin
      if (wren) begin
        mem[waddr] <= din;
      end
   end

   assign dout = mem[raddr];

   // You should write the mem initial data into mem.txt in advance.
   initial begin
      $readmemb( "./mem.txt" , mem) ;
   end

endmodule
