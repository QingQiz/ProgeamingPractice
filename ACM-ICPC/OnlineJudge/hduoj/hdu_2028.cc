#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while (a^=b^=a^=b%=a);
    return b;
        
}

int main(int argc, char const* argv[])
{
    int n;
    while (cin >> n) {
        int *aim = new int[n],ans;
        for (int i = 0; i < n; i++) {
            cin >> aim[i];
            if(i==1)
                ans=aim[1]*aim[0]/gcd(aim[1],aim[0]);
            if(i>1)
                ans=aim[i]*ans/gcd(aim[i],ans);
        }
        cout << ans << endl;
    }
    return 0;
}
