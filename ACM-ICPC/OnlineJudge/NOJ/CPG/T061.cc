#include<stdio.h>
int main()
{
    char A[80];
    gets(A);
    char c;
    scanf("%c",&c);
    int n,i,j=0;
    scanf("%d",&n);
    char B[80],C[80];
    for(i=0;i<n;i++)
        B[i]=A[i];
    B[i]='\0';
    for(i=n;i<80;i++){
        C[j]=A[i];
        if(C[j]=='\0')
            break;
        j++;
    }
    B[n]=c,B[n+1]='\0';
    printf("%s%s",B,C);
}