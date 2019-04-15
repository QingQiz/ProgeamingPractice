module booth (/*AUTOARG*/
   // Outputs
   c, finish,
   // Inputs
   a, b, CLK, Beg
   ) ;
   output [63:0] c;
   output reg        finish;
   input [31:0]      a, b;
   input             CLK, Beg;

   reg [64:0]        A, P;
   reg [64:0]        A_1, A2, A_2;
   reg [7:0]         index_i;


   reg [1:0]         current_state, next_state;
   parameter Init=0, Ready=1, Acc=2, Done=3;

   always @(posedge CLK or negedge Beg) begin
     if (!Beg) current_state <= Init;
     else current_state <= next_state;
   end
   always @ (current_state or index_i) begin
      case (current_state)
        Init: begin
           next_state = Ready;
           finish = 0;
        end
        Ready: begin
           next_state = Acc;
           A = {a[31:0], 33'h0};
           A2 = {a[30:0], 34'h0};
           A_2 = {(~a[30:0]) + 1'b1, 34'b0};
           A_1 = {(~a[31:0]) + 1'b1, 33'b0};
           P = {32'h0, b[31:0], 1'b0};
        end
        Acc: begin
           if (index_i == 8'h0f) next_state = Done;
           case (P[2:0])
             3'b001: begin
                P = P + A;
             end
             3'b010: begin
                P = P + A;
             end
             3'b011: begin
                P = P + A2;
             end
             3'b100: begin
                P = P + A_2;
             end
             3'b101: begin
                P = P + A_1;
             end
             3'b110: begin
                P = P + A_1;
             end
           endcase // case (cb[2:0])
           P = {P[64], P[64], P[64:2]};
        end
        default: begin
           finish = 1;
        end
      endcase // case (current_state)
   end

   always @ (posedge CLK) begin
      if (current_state == Acc) index_i <= index_i + 1;
      else index_i <= 0;
   end
   assign c = P[64:1];
endmodule // booth
