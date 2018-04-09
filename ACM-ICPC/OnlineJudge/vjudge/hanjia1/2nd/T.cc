#include <cstdio>
using namespace std;
int min(int a,int b){
    return a>b?b:a;
}
int main(){
    int n,s;
    while (scanf("%d%d",&n,&s)==2) {
        long long ans=0;
        int c_min=5001;
        for (int i = 0; i < n; i++) {
            int c,a;
            scanf("%d%d",&c,&a);
            c_min=min(c,c_min+s);
            ans+=c_min*a;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/T
//贪心
//贪心策略:此次购买价格或者是上次生产的价格加上s(存储),或者时这次购买的价格,而我们选择其中的较小值
//
//证明:
//设该策略为A且不是最优策略,设最优策略为O,且O恰在从第k次开始产生不同的选择
//因为A的选择每次都是两者中的小值,所以在产生分歧时,A选择的花费小于等于O选择的花费
//假设策略O'与策略O仅在第k次选择不同,且O'在第k次选择与A相同,
//则O'在第k次的花费比O小,所以O'的总花费小于等于O的
//所以O'是比O更优的策略,这与O是最优策略矛盾,所以假设错误,所以A是最优策略
