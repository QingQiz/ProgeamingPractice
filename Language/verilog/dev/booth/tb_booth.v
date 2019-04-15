`timescale 1ns/1ns

module tb_booth;
   // Inputs
   reg [31:0] a;
   reg [31:0] b;
   reg        start;
   reg        clk;

   // Outputs
   wire       done;
   wire [63:0] c;

   // Instantiate the Unit Under Test (UUT)
   booth uut (
              .finish(done),
              .c(c),
              .a(a),
              .b(b),
              .Beg(start),
              .CLK(clk)
              );

   initial begin
      // Initialize Inputs
      a = 0;
      b = 0;
      start = 0;
      clk = 0;

      // Wait 100 ns for global reset to finish
      #100;

      // Add stimulus here
      start=1;

      a=32'h1101_1101;
      b=32'h1001_1011;

      #500;
      $stop;
   end
   always #10 clk=~clk;

   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, tb_booth);
   end
endmodule
