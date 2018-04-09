#include <stdio.h>
#include<string.h>
int main()
{
    int i;
    char A[12][5]={"I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII"};
    char B[5];
    scanf("%s",B);
    for (i = 0; i < 12; i++) {
        if(strcmp(A[i],B)==0)
            printf("%d",++i);
    }
    return 0;
}