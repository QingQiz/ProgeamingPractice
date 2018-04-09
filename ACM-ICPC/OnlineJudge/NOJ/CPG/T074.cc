#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ANS[101];
int main()
{
    char A[100],B[100];
    int LA,LB,*p,*q,flg_A,flg_B,jud_A,jud_B,flg=0,i;
    scanf("%s%s",A,B);
    LA=strlen(A);
    LB=strlen(B);
    flg_A=A[0]=='-'?1:0,jud_A=A[0]=='-'?-1:1;
    flg_B=B[0]=='-'?1:0,jud_B=B[0]=='-'?-1:1;
    p=(int*)malloc((LA-flg_A)*sizeof(int));
    q=(int*)malloc((LB-flg_B)*sizeof(int));
    for(i=0;i<LA-flg_A;i++)p[i]=jud_A*((int)A[i+flg_A]-48);
    for(i=0;i<LB-flg_B;i++)q[i]=-1*jud_B*((int)B[i+flg_B]-48);
    for(i=0;i<=(LA-flg_A<LB-flg_B?LA-flg_A:LB-flg_B);i++){
        ANS[101-i]=p[LA-flg_A-i]+q[LB-flg_B-i];
    }
    for(;i<=(LA-flg_A>LB-flg_B?LA-flg_A:LB-flg_B);i++){
        if(LA-flg_A>LB-flg_B)
            ANS[101-i]=p[LA-flg_A-i];
        else 
            ANS[101-i]=q[LB-flg_B-i];
    }
    for(i=0;i<101-(LA-flg_A>LB-flg_B?LA-flg_A:LB-flg_B);i++)ANS[i]=0;
    for(i=0;i<101;i++){
        ANS[100-i-1]+=ANS[100-i]/10;
        ANS[100-i]%=10;
    }
    i=0;
    while(ANS[i++]<=0&&i<101);
    if(i!=101){
        for(i=0;i<101;i++){
            if(ANS[100-i]<0){
                ANS[100-i-1]-=1;
                ANS[100-i]+=10;
            }
        }
    }
    else for(i=0;i<101;i++)ANS[i]*=-1,flg=-1;
    i=0;
    while(ANS[i++]==0);i--;
    switch(flg){
        case 0:{
                   for(;i<101;i++)printf("%d",ANS[i]);
                   break;
               }
        case-1:{
                   putchar('-');
                   for(;i<101;i++)printf("%d",ANS[i]);
                   break;
               }
    }
    free(p);
    free(q);
    return 0;
}