`timescale 1ns/1ns

module tde2t4 (/*AUTOARG*/ ) ;
   reg   [1:0] in;
   wire   [3:0] out;

   always #20 in = in + 1;

   initial begin
      #0 in = 2'b00;
      #100 $stop;
   end

   de2t4 test(out, in);

   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, tde2t4);
   end
endmodule // tde2t4
