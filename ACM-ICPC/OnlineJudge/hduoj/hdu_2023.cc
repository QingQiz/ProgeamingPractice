#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[])
{
    int n,m,sour[50][5];
    double save[5],cave[50];
    while (cin >> n >> m) {
        memset(save,0,sizeof(save));
        memset(cave,0,sizeof(cave));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> sour[i][j];
                cave[i]+=sour[i][j]/double(m);
            }
        }
        for(int i=0;i<n;i++){
            if(i)cout << ' ';
            printf("%.2lf",cave[i]);
        }
        cout << endl;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                save[i]+=sour[j][i]/double(n);
            if(i)cout << ' ';
            printf("%.2lf",save[i]);
        }
        cout << endl;

        int sum=0,flg;
        for(int i=0;i<n;i++){
            flg=1;
            for(int j=0;j<m;j++)
                if(sour[i][j]<save[j])flg=0;
            if(flg)sum++;
        }
        cout << sum << endl << endl;

    }
    return 0;
}
