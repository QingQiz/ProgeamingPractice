module imem( addr, dout );

   input [11:2] addr;
   input [31:0] dout;

   reg [31:0]   imem[1023:0];

   assign dout = imem[addr];

   // You should generate the mips machine codes into imem.txt from MARS.
   initial begin
      $readmemb( "../src/imem.txt" , imem) ;
   end

endmodule
