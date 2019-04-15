`timescale 1ns/1ns

module tcounter (/*AUTOARG*/) ;
   reg clock, reset;
   wire q0, q1, q2, q3;


   always #5 clock = ~clock;

   initial begin
      #0 clock = 0; reset = 1;
      #200 $stop;
   end

   assign {q3, q2, q1, q0} = 4'b0000;
   counter test({q0, q1, q2, q3}, clock, reset);

   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, tcounter);
   end

endmodule // tcounter
