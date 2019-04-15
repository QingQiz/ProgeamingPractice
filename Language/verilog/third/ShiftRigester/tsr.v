`timescale 1ns/1ns

module tsr (/*AUTOARG*/ ) ;
   reg in, clk;
   wire [0:3]q;


   always #5 clk = ~clk;

   initial begin
      #0 clk = 0; in = 0;
      #5 in = 1;
      #10 in = 0;
      #15 in = 1;
      #20 in = 0;
      #30 in = 1;
      #40 in = 0;
      #45 in = 1;
      #50 in = 0;
      #60 in = 1;
      #65 in = 0;
      #75 in = 1;
      #80 in = 0;
      #85 in = 1;
      #95 in = 0;
      #100 in = 1;
      #105 in = 0;
      #110 in = 1;
      #120 in = 0;
      #125 in = 1;
      #130 in = 0;
      #140 in = 1;
      #145 in = 0;
      #155 in = 1;
      #165 in = 0;
      #170 in = 1;
      #180 in = 0;
      #190 in = 1;
      #195 in = 0;
      #205 in = 1;
      #215 in = 0;
      #220 $stop;
   end

   sr test(q, in, clk);

   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, tsr);
   end
endmodule // tsr
