#include <stdio.h>
int main()
{
    char A[3][80];
    gets(A[0]);
    gets(A[1]);
    gets(A[2]);
    int sum_B=0,sum_S=0,sum_N=0,sum_=0,sum_O,sum=0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 80; j++) {
            if(A[i][j]>64&&A[i][j]<91)sum_B++;
            else if(A[i][j]>96&&A[i][j]<123)sum_S++;
            else if(A[i][j]>47&&A[i][j]<58)sum_N++;
            else if(A[i][j]==32)sum_++;
            if(A[i][j]=='\0')break;
            sum++;
        }
    }
    sum_O=sum-sum_-sum_B-sum_N-sum_S;
    printf("%d %d %d %d %d",sum_B,sum_S,sum_N,sum_,sum_O);
    return 0;
}