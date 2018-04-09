#include<cstdio>
#include<ctime>
#include<algorithm>
#define maxn 10000
using namespace std;

int flag;
int n,m;
int a[maxn+5];
int sum[maxn+5];
bool prime[maxn+5];

int judge(int mid)
{
    for(int i=1;i<=m;i++)
    {
        if(a[i]==1) continue;
        int left=max(1,i-mid);
        int right=min(m,i+mid);
        int cnt=sum[right]-sum[left-1];
        if(prime[i])
        {
            if(cnt>=n-1) return 1;
        }
        else
        {
            if(cnt>=n) return 1;
        }
    }
    return 0;
}

void solve()
{
    int ans=-1;
    int left=1,right=m;
    while(right>=left)
    {
        int mid=(left+right)>>1;
        if(judge(mid))
        {
            ans=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    if(ans!=-1)
    {
        printf("%d\n",ans);
        flag++;
    }
    else
    {
        printf("So Sad\n");
    }
}

bool isprime(int num)
{
    if(num==1) return false;
    for(int i=2;i<=num/i;i++)
    {
        if(num%i==0) return false;
    }
    return true;
}

void getprime()
{
    for(int i=1;i<=maxn;i++)
    {
        prime[i]=isprime(i);
    }
}

void getsum()
{
    sum[0]=0;
    for(int i=1;i<=m;i++)
    {
        if(a[i]==1 || prime[i])
        {
            sum[i]=sum[i-1];
        }
        else
        {
            sum[i]=sum[i-1]+1;
        }
    }

//    for(int i=0;i<=m;i++)
//    {
//        printf("%d ",sum[i]);
//    }
//    printf("\n");
}

int main()
{
    //int start,finish;
    //start=clock();
    //freopen("L_in.txt","r",stdin);
    //freopen("L_out.txt","w",stdout);
    int T;
    getprime();
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
        }
        getsum();
        printf("Case #%d: ",kase);
        solve();
    }
    //finish=clock();
    //printf("sum=%d time=%d\n",flag,finish-start);
    return 0;
}
