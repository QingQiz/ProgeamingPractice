`timescale 1ns/1ns

module tcmp1 (/*AUTOARG*/ ) ;
   reg   x, y;
   wire   xgty, xeqy, xlsy;

   always #10 x = ~x;
   always #20 y = ~y;

   initial begin
      #0 x = 0; y = 0;
      #50 $stop;
   end

   cmp1 test(xgty, xeqy, xlsy, x, y);

   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, tcmp1);
   end

endmodule // tcmp1
