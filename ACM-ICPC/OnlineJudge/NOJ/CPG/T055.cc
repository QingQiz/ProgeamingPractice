#include <stdio.h>
int main()
{
    char A[100],B[100];
    gets(A);
    char *p=B,*q=A;
    int sum_1=0,sum_2=0,flg,flg_2=1;
    while(*q++){
        if(flg_2==1){
            q-=1;
            flg_2=0;
        }
        if(*q<59&&*q>47){
            *p++=*q;
            sum_1++;
            flg=1;
        }
        else if(flg==1){
            flg=0;
            *p++='\x20';
            sum_2++;
        }
    }
    *--p='\0';
    p-=sum_1+sum_2-1;
    printf("%d\n",sum_2);
    printf("%s",p);
    return 0;
}