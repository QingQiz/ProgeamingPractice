#include <bits/stdc++.h>
bool cmp(int a,int b){
    return a>b;
}
int A[1000000];
int main(int argc, char const* argv[])
{
    using namespace std;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++)
            scanf("%d",A+i);
        sort(A,A+n,cmp);
        for(int i=0;i<m;i++){
            if(i)printf(" ");
            printf("%d",A[i]);
        }
        cout << endl;
    }
    return 0;
}
