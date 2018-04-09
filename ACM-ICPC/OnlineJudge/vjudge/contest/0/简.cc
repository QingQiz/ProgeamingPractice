#include <bits/stdc++.h>
int aim[1000][1000],ans[1000][1000];
int main(int argc, char const* argv[])
{
    using namespace std;
    int T;
    cin >> T;
    while (T--) {
        int m,n,x,y;
        int max=0,sum;
        cin >> m >> n >> x >> y;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cin >> aim[i][j];
                if(j-1)aim[i][j]+=aim[i][j-1];
                if(i-x>=0 && j-y>=0){
                    sum=0;
                    for(int k=i-x+1;k<=i;k++)
                        sum+=aim[k][j]-aim[k][j-y];
                    if(max<sum)max=sum;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}
