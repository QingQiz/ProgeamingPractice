#include<stdio.h>
#include<string.h>
int ANS[126];
int ans[126];
int main()
{
    char A[7];
    int B[6],s,LENA;
    int i=0,j=0,n,k,flg,N;
    scanf("%s",A);
    scanf("%d",&n);
    N=n;
    LENA=strlen(A);
    for(;j<LENA;i++,j++){
        if(A[j]=='.')i--,flg=j;
        else B[i]=(int)A[j]-48;
    }
    for(i=0;i<LENA-1;i++)
        ANS[125-i]=B[LENA-2-i];
    while(n>1){
        for(i=0;i<LENA-1;i++){
            s=0;
            for(j=0;j<126;j++){
                s=s/10+ANS[125-j]*B[LENA-2-i];
                ans[125-j-i]+=s%10;
            }
            ans[125-i-j-1]+=s/10;
        }
        for(k=0;k<126;k++){
            ans[125-k-1]+=ans[125-k]/10;
            ans[125-k]%=10;
        }
        for(int i=0;i<126;i++)ANS[i]=ans[i];
        for(int i=0;i<126;i++)ans[i]=0;
        n--;
    }
    i=0;
    while(ANS[i++]==0);i--;
    k=0;
    while(ANS[125-(k++)]==0);k--;
    for(;i<126-k;i++){
        printf("%d",ANS[i]);
        if(125-i==(LENA-flg-1)*N&&ANS[i+1]!=0)
            putchar('.');
    }
    return 0;
}