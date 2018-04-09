#include <iostream>
#include <map>
using namespace std;
const int n=1010;
int f[n];
int find(int x){
    if(f[x]==x)return f[x];
    return f[x]=find(f[x]);
}
void merge(int v,int u){
    f[u]=find(v);
}
map<int ,int >mmp;
int main(int argc, char const* argv[])
{
    int n,m,l,r;
    while (cin >> n && n) {
        cin >> m;
        mmp.clear();
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
        for(int i=0;i<m;i++){
            cin >> l >> r;
            mmp[l]++;
            mmp[r]++;
            if(find(l)!=find(r))
                merge(l,r);
        }
        int flg=0;
        for(map<int,int>::iterator it=mmp.begin();it!=mmp.end();it++){
            if(it->second&1){
                cout << '0' << endl;
                flg=1;
                break;
            }
        }
        if(flg)continue;
        int x=f[1];
        for(int i=2;i<=n;i++){
            if(find(i)!=x){
                flg=1;
                break;
            }
        }
        if(flg)
            cout << '0' << endl;
        else 
            cout << '1' << endl;
    }
    return 0;
}

//https://vjudge.net/contest/206616#rank
//欧拉回路的条件是图是连通的，并且没有奇数度的结点
//
//图的连通性可以通过并查集实现，如果所有结点的根都相同，则连通
//结点的度可以通过map来计算。
