#include <bits/stdc++.h>
using namespace std;
class TIME {
private:
    int h,m,s;
public:
    TIME operator+(const TIME & p) const{
        TIME ans;
        ans.s=p.s+s,ans.m=p.m+m,ans.h=p.h+h;
        ans.m+=ans.s/60,ans.h+=ans.m/60;
        ans.s%=60,ans.m%=60;
        return ans;
    }
    friend istream & operator>>(istream & is ,TIME & p){
        is >> p.h >> p.m >> p.s;
        return is;
    }
    friend ostream & operator<<(ostream & os ,TIME & p){
        os << p.h << ' ' << p.m << ' ' << p.s << endl;
        return os;
    }
};

int main(int argc, char const* argv[])
{
    int N;
    cin >> N;;
    while (N--) {
        TIME p,q,ans;
        cin >> p >> q;
        ans=p+q;
        cout << ans;
    }
    return 0;
}
