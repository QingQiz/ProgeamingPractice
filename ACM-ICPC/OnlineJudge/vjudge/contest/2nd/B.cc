#include <iostream>
#include <cstring>
using namespace std;

char a[21][21];
int book[21][21],n,m,sum;
void dfs(int x,int y){
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
        if(a[nowx][nowy]=='.' && book[nowx][nowy]==0){
            sum++;
            book[nowx][nowy]=1;
            dfs(nowx,nowy);
        }
    }
    return ;
}

int main(int argc, char const* argv[])
{
    while (cin >> m >> n && (n || m)) {
        int x,y;
        memset(book,0,sizeof(book));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
                if(a[i][j]=='@')
                    x=i,y=j;
            }
        }
        sum=1;
        book[x][y]=1;
        dfs(x,y);
        cout << sum << endl;
    }
    return 0;
}
