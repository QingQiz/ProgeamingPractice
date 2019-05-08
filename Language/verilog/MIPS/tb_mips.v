`timescale 1ns/1ps

module tb_mips();

   reg clk, rst;
   wire [31:0] imem_addr;
   wire [31:0] imem_dout;
   wire [31:0] dmem_addr;
   wire [31:0] dmem_din;
   wire [3:0]  dmem_be;
   wire        dmem_wren;
   wire [31:0] dmem_dout;
   integer i;

   mips U_MIPS(
               .clk(clk),
               .rst(rst),
               .imem_addr(imem_addr),
               .imem_dout(imem_dout),
               .dmem_addr(dmem_addr),
               .dmem_din(dmem_din),
               .dmem_be(dmem_be),
               .dmem_wren(dmem_wren),
               .dmem_dout(dmem_dout)
               );

   imem U_IMEM(
               .addr(imem_addr[11:2]),
               .dout(imem_dout)
               );

   dmem U_DMEM(
               .clk(clk),
               .addr(dmem_addr[11:2]),
               .din(dmem_din),
               .be(dmem_be),
               .wren(dmem_wren),
               .dout(dmem_dout)
               );

   initial begin
      // Removed if you use the Xilinx IP
      //$readmemh( "code.txt" , U_MIPS.U_IM.imem ) ;
      $monitor("PC = 0x%8X, IR = 0x%8X", U_MIPS.pc, U_IMEM.dout);
      clk = 1 ;
      rst = 1 ;
      #500 ;
      rst = 0 ;
      #20000;
      $stop;
   end
   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, tb_mips);
      for (i = 0; i < 32; i = i + 1) begin
          $dumpvars(0, U_DMEM.dmem[i]);
          $dumpvars(0, U_MIPS.U_RF.rf[i]);
      end
   end

   always
     #(50) clk = ~clk;

endmodule
