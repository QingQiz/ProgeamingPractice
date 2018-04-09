#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=100010;
class AC{
public:
    int l;
    int r;
    bool operator<(const AC C)const {
        if(l!=C.l)
            return l<C.l;
        return r<C.r;
    }
}dat[maxn];
vector<AC> vec;

int main(){
    int n,m;
    while (cin >> n >> m) {
        vec.clear();
        for(int i=0;i<n;i++){
            cin >> dat[i].l >> dat[i].r;
        }
        sort(dat,dat+n);
        vec.push_back(dat[0]);
        for(int i=1;i<n;i++){
            auto it =vec.end()-1;
            if((*it).r>=dat[i].l){
                (*it).r=(*it).r>dat[i].r?(*it).r:dat[i].r;
                (*it).l=(*it).l<dat[i].l?(*it).l:dat[i].l;
            }
            else {
                vec.push_back(dat[i]);
            }
        }
        int sn=vec.size();
        int *s_d = new int[sn+1];
        s_d[0]=0;
        for(int i=1;i<=sn;i++){
            s_d[i]=s_d[i-1]+vec[i-1].r-vec[i-1].l+1;
        }
        int L=1, R=1;
        long long ans=0;
        while (1) {
            long long num;
            while (R<=sn && (num = vec[R-1].r-vec[L-1].l+1-(s_d[R]-s_d[L-1]))<=m) {
                long long cmp=vec[R-1].r-vec[L-1].l+1;
                ans=cmp>ans?cmp:ans;
                R++;
            }
            if(num<=m)break;
            long long CMP = s_d[R-1]-s_d[L-1]+m;
            ans=ans>CMP?ans:CMP;
            L++;
        }
        ans=ans>(s_d[sn]-s_d[L-1]+m)?ans:(s_d[sn]-s_d[L-1]+m);
        cout << ans << endl;
        delete [] s_d;
    }
    return 0;
}
