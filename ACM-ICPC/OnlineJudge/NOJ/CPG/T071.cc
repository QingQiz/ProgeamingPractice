#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int ANS[200];
int main()
{
   char A[100],B[100];
   int *p,*q,LA,LB,flg,s,j;
   scanf("%s%s",A,B);
   LA=(int)strlen(A);
   LB=(int)strlen(B);
   p=(int*)malloc(LA*sizeof(int));
   q=(int*)malloc(LB*sizeof(int));
   for(int i=0;i<LA;i++)p[i]=(int)A[i]-48;
   for(int i=0;i<LB;i++)q[i]=(int)B[i]-48;
   for(int i=0;i<LB;i++){
       flg=0;
       for(j=LA-1;j>-1;j--){
           if(flg==0){
               s=q[LB-i-1]*p[j];
               flg=1;
           }
           else s=s/10+q[LB-i-1]*p[j];
           ANS[200+j-i-LA]+=s%10;
       }
       ANS[199-i-j]+=s/10;
   }
   for(int i=0;i<199;i++){
       ANS[198-i]+=ANS[199-i]/10;
       ANS[199-i]%=10;
   };
   int i=0;
   while(ANS[i]==0)i++;
   for(;i<200;i++)printf("%d",ANS[i]);
   free(p);
   free(q);
   return 0;
}