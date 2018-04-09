#include <iostream>
#include <cstring>
using namespace std;

char a[101][101];
int book[101][101],n,m;
void dfs(int x,int y,int cmp){
    int next[4][2]={
        0,1,
        1,0,
        0,-1,
        -1,0
    };
    int nowx,nowy;
    for(int k=0;k<=3;k++){
        nowx=x+next[k][0];
        nowy=y+next[k][1];
        if(nowx<1 || nowx > n || nowy<1 || nowy>m)
            continue;
        if(a[nowx][nowy]==cmp && book[nowx][nowy]==0){
            book[nowx][nowy]=1;
            a[nowx][nowy]='#';
            dfs(nowx,nowy,cmp);
        }
    }
    return ;
}

int main() {
    while (cin >> m >> n && (n || m)) {
        memset(book,0,sizeof(book));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
            }
        }
        int cnt=0;
        int flg1=0,flg2=0;
        if(a[1][1]=='0')flg2=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==-1)continue;
                if(a[i][j]=='1')flg1++;
                dfs(i,j,a[i][j]);
                cnt++;
            }
        }
        if(cnt==2 && flg2==1)cout << '1';
        else if(cnt==3 && flg1==1)cout << '0';
        else cout << "-1";
        cout << endl;
    }
    return 0;
}
