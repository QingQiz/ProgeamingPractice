#include <stdio.h>
void change(int A[],int n,int first ,int last);
int main()
{
    int N;
    scanf("%d",&N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d",&A[i]);
    }
    int m,n;
    scanf("%d%d",&m,&n);
    //int B[n-m+1],ff=m;
    //for (int i = 0; i < n-m+1; i++) {
    //    B[i]=A[ff];
    //    ff++;
    //}
    //change(B,n-m+1,0,n-1);
    //for (int i = 0; i < n; i++) {
    //    A[m]=B[i];
    //    m++;
    //}
    change(A,N,m,n);
    for (int i = 0; i < N; i++) {
        printf("%d ",A[i]);
    }
    return 0;
}
void change(int A[],int n,int first ,int last)
{
    int t,i,j;
    i=first,j=last+1;
    if (first<last) {
        while (1) {
           while (i<n-1&&A[++i]>A[first]) {
               ;
           } 
           while (j-1>-1&&A[--j]<A[first]) {
               ;
           }
           if(i>=j)
               break;
           t=A[i],A[i]=A[j],A[j]=t;
        }
        t=A[first],A[first]=A[j],A[j]=t;
        change(A,n,first,j-1);
        change(A,n,j+1,last);
    }
}
