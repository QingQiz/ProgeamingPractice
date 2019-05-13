 `timescale 1ns/1ps

module tb_mips();
    
   reg clk, rst;
   wire  [31:0] mem_waddr;
   wire  [31:0] mem_raddr;
   wire  [31:0] mem_din;
   wire         mem_wren;
   wire [31:0]  mem_dout;
   integer i;
    
   mips U_MIPS(
      .clk(clk), 
      .rst(rst), 
      .mem_waddr(mem_waddr), 
      .mem_raddr(mem_raddr), 
      .mem_din(mem_din), 
      .mem_wren(mem_wren), 
      .mem_dout(mem_dout)
   );

   mem U_MEM(
      .clk(clk), 
      .waddr(mem_waddr[11:2]), 
      .raddr(mem_raddr[11:2]), 
      .din(mem_din), 
      .wren(mem_wren), 
      .dout(mem_dout)
   );
    
   initial begin
      // Removed if you use the Xilinx IP
      //$readmemh( "code.txt" , U_MIPS.U_IM.imem ) ;
      //$monitor("PC = 0x%8X, IR = 0x%8X", U_MIPS.pc, U_MIPS.ir); 
      clk = 1 ;
      rst = 1 ;
      #500 ;
      rst = 0 ;
      #10000;
      $finish;
   end
   
   initial begin
      $dumpfile("out.vcd");
      $dumpvars(0, tb_mips);
      for (i = 0; i < 32; i = i + 1) begin
          $dumpvars(0, U_MEM.mem[i]);
          $dumpvars(0, U_MIPS.U_RF.rf[i]);
      end
   end
   always
	   #(50) clk = ~clk;
   
endmodule
