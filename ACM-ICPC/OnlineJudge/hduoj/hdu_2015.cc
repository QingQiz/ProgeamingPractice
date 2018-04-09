#include <bits/stdc++.h>
#define swap(a,b) ((a)=(a)^(b),(b)=(a)^(b),(a)=(a)^(b))
#define DISTANCE(_,__) \
    (_.x-__.x)*(_.x-__.x)+(_.y-__.y)*(_.y-__.y)
#define PI acos(-1)
#define abs(_) (_)>0?(_):(-_)
#define dou(_) (_)*(_)
#define tri(_) (_)*(_)*(_)
int main(int argc, char const* argv[])
{
    using namespace std;
    int n,m;
    while (cin >> n >> m) {
        int *ans =new int[n+1];
        for(int i=0;i<=n;i++)ans[i]=i*i+i;
        if(m<n){
            int i;
            for(i=1;i+m-1<=n;i+=m){
                if(i!=1)cout << ' ' ;
                cout << (ans[i+m-1]-ans[i-1])/m;
            }
            if(i<=n)
                cout << ' ' << (ans[n]-ans[i-1])/(n-i+1) ;
            cout << endl;
        }
        else cout << ans[n]/n << endl;
    }
    return 0;
}
