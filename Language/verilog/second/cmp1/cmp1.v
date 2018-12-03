module cmp1 (/*AUTOARG*/
   // Outputs
   xgty, xeqy, xlsy,
   // Inputs
   x, y
   ) ;
   input x, y;
   output xgty, xeqy, xlsy;

   reg   xgty, xeqy, xlsy;

   always @ ( /*AUTOSENSE*/x or y) begin
      assign xeqy = ~(x ^ y);
      assign xgty = x ^ y ? x : 0;
      assign xlsy = x ^ y ? y : 0;
   end

endmodule // cmp1
