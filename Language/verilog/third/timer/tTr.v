`timescale 1ns/1ns

module tTr (/*AUTOARG*/) ;
   reg clk, e, resetn;
   wire [4:0] q;
   wire       led;

   initial begin
      e = 1;
      clk = 1;
      resetn = 1;
      #10000 $stop;
   end

   always #25 clk = ~clk;
   always #750 resetn = ~resetn;


   Tr test(led, q, resetn, clk, e);

   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, tTr);
   end
endmodule // tTr
