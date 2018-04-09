#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    while (cin >> n) {
        int ans[30][30];
        memset(ans,0,sizeof(ans));
        ans[0][0]=1;
        for(int i=1;i<n;i++)
            for(int j=0;j<=i;j++){
                if(j==0)ans[i][j]=1;
                else ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j)cout << ' ';
                cout << ans[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
