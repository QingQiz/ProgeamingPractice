`timescale 1ns/1ns

module td (/*AUTOARG*/) ;
   wire q, nq;
   reg  clock, d;

   always #10 clock = ~clock;

   initial begin
      #0 clock = 0; d = 0;
      #5 d = 1;
      #25 d = 0;
      #45 d = 1;
      #55 d = 0;
      #62 d = 1;
      #63 d = 0;
      #75 d = 1;
      #85 d = 0;
      #100 $stop;
   end

   d test(q, nq, d, clock);

   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, td);
   end
endmodule // td
