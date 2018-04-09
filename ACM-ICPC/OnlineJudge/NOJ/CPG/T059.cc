#include <stdio.h>
int main()
{
    char A[50],p;
    gets(A);
    scanf("%c",&p);
    char *test;
    while(1){
        test=A-1;
        while(*++test!=p&&*test!='\0');
        if(*test=='\0')break;
        while(*test++=*test);
    }
    printf("%s",A);
    return 0;
}