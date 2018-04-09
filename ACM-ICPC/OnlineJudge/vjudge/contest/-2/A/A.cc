#include<cstdio>
#include<algorithm>
#define maxn 20
using namespace std;

int n;
int a[maxn+5];

int solve()
{
    int sum=0,t=1;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        //printf("%d\n",t);
        sum+=a[i]*t;
        t<<=1;
    }
    return sum;
}

int main()
{
    freopen("A_in.txt","r",stdin);
    freopen("A_out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Case #%d: %d\n",kase,solve());
    }
    return 0;
}
