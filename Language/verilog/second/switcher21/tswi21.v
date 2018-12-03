`timescale 1ns/1ns

module tswi21 (/*AUTOARG*/ ) ;
   reg x1, x0, m;
   wire f;

   always #40 m = ~m;
   always #10 x0 = ~x0;
   always #20 x1 = ~x1;

   initial begin
      #0 m = 0; x0 = 0; x1 = 0;
      #100 $stop;
   end

   swi21 test(f, x1, x0, m);

   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, tswi21);
   end

endmodule // tswi21
