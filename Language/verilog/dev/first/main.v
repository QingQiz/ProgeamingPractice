module main (/*AUTOARG*/
   // Outputs
   TxD,
   // Inputs
   D, CLK2M, FS, RESET, A0, CS, WR, RD
   ) ;
   input [7:0] D;
   input       CLK2M, FS;
   input       RESET;
   input       A0, CS, WR, RD;
   output reg      TxD;
   reg [7:0]   THR0, THR1, THR2, THR3, TSR;
   reg        THR_EMPTY0, THR_EMPTY1, THR_EMPTY2, THR_EMPTY3;
   reg        THR_EMPTY, TxD_FREE;
   reg [7:0]  TSR_EMPTY;
   reg [2:0]  READ;

   always @(posedge CLK2M) begin
      if (FS == 0) READ = 4;
      if (RESET) begin
         THR_EMPTY0 = 1;
         THR_EMPTY1 = 1;
         THR_EMPTY2 = 1;
         THR_EMPTY3 = 1;
         TSR_EMPTY = 8'b11111111;
         TxD_FREE = 1;
      end
      if (TSR_EMPTY & (THR_EMPTY == 8'b11111111)) begin
         TSR = 8'b00000000;
         casex ({THR_EMPTY3, THR_EMPTY2, THR_EMPTY1, THR_EMPTY0})
           4'b0xxx: begin
              TSR = THR3;
              THR_EMPTY3 = 1;
           end
           4'b10xx: begin
              TSR = THR2;
              THR_EMPTY2 = 1;
           end
           4'b110x: begin
              TSR = THR1;
              THR_EMPTY1 = 1;
           end
           4'b1110: begin
              TSR = THR0;
              THR_EMPTY0 = 1;
           end
         endcase // casex
      end
      if (WR & TSR_EMPTY != 8'b11111111) begin
         TxD <= TSR[7];
         TSR <= TSR << 1;
         TSR_EMPTY <= (TSR_EMPTY | 8'b00000001) << 1;
         TxD_FREE = 0;
      end
      if (THR_EMPTY && TSR_EMPTY == 8'b11111111) begin
         TxD_FREE = 1;
      end
      assign THR_EMPTY = THR_EMPTY0 & THR_EMPTY1 & THR_EMPTY2 & THR_EMPTY3;
      if (TxD_FREE) begin
         TSR_EMPTY = 0;
         TSR = 8'b0111110;
      end
      if (RD & (READ != 0)) begin
         casex ({THR_EMPTY3, THR_EMPTY2, THR_EMPTY1, THR_EMPTY0})
           4'b1xxx: begin
              THR3 = D;
              THR_EMPTY3 = 0;
           end
           4'b01xx: begin
              THR2 = D;
              THR_EMPTY2 = 0;
           end
           4'b001x: begin
              THR1 = D;
              THR_EMPTY1 = 0;
           end
           4'b0001: begin
              THR0 = D;
              THR_EMPTY0 = 0;
           end
         endcase // casex
         READ = READ - 1;
      end
   end
endmodule // main
