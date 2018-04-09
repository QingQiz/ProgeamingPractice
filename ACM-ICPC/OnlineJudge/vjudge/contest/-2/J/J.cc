#include<cstdio>
using namespace std;

int solve(int n)
{
    return (n+1)/2+(n+1)/3-(n+1)/6+1;
}

int main()
{
    freopen("J_in.txt","r",stdin);
    freopen("J_out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",kase,solve(n));
    }
    return 0;
}
