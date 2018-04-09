#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 1000000
int cnt[maxn];

int main(int argc, char const* argv[])
{
    int n;
    while (cin >> n) {
        int mid;int ans=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            scanf("%d",&mid);
            cnt[mid]++;
            if(cnt[mid]>(n+1)/2)
                ans=mid;
        }
        cout << ans << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/J
//用类似桶排序的方法对出现的数字进行计数，如果某个计数超过了(n+1)/2
//则为所求
//这种问题好像叫主元素问题。。。
