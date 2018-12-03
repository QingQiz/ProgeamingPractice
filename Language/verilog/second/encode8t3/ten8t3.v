`timescale 1ns/1ns

module ten8t3 (/*AUTOARG*/ ) ;
   reg   [7:0] in;
   wire [2:0]  out;

   always #1 in = in + 1;

   initial begin
      #0 in = 8'b00000000;
      #300 $stop;
   end

   en8t3 test(out, in);

   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, ten8t3);
   end
endmodule // ten8t3
