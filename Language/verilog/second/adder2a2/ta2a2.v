`timescale 1ns/1ns

module ta2a2 (/*AUTOARG*/ ) ;
   reg [1:0] x, y;
   reg       c0;
   wire [1:0] s;
   wire       c;

   always #10 x = x + 1;
   always #40 y = y + 1;
   always #160 c0 = ~c0;

   initial begin
      #0 x = 2'b00; y = 2'b00; c0 = 0;
      #400 $stop;
   end

   a2a2 test(s, c, x, y, c0);


   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, ta2a2);
   end

endmodule // ta2a2
