#include<cstdio>
using namespace std;

int main()
{
    freopen("H_in.txt","r",stdin);
    freopen("H_out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        int n;
        scanf("%d",&n);
        if(n==2 || n==3)
        {
            printf("Case #%d: Yes\n",kase);
        }
        else
        {
            printf("Case #%d: No\n",kase);
        }
    }
    return 0;
}
