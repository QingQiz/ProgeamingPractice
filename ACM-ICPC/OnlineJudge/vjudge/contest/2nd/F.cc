#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    while (n--) {
        ll l,r,k;
        cin >> l >> r;
        k=l^r;
        int len=k==0?0:(int)log2((double)k)+1;
        ll ans=(1ll<<len)-1;
        cout << (ans|r) << endl;
    }
    return 0;
}
