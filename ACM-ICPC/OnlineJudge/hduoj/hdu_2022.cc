#include <bits/stdc++.h>
using namespace std;
int abs(int aim){
    return aim>0?aim:-aim;
}
int main(int argc, char const* argv[])
{
    struct sour {
        int x,y;
        int sour;
    };
    int m,n;
    while (cin >> m >> n) {
        int sourse;
        sour ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> sourse;
                if((i==0&&j==0) || abs(sourse) > abs(ans.sour))
                    ans.x=i+1,ans.y=j+1,ans.sour=sourse;
            }
        }
        cout << ans.x << ' ' << ans.y << ' ' << ans.sour << endl;
    }
    return 0;
}
