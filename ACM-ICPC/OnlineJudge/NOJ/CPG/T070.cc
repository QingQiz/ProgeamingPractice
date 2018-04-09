#include <stdio.h>
int main()
{
    char A[50],B[50],*p=A;
    int j=0,k=0;
    gets(A);
    while(*p++){
        if (k%2!=0&&(int)A[k]%2!=0) {
            B[j++]=A[k];
        }
        k++;
    }
    B[j]='\0';
    printf("%s",B);
    return 0;
}