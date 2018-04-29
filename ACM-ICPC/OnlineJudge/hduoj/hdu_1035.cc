#include <bits/stdc++.h>
using namespace std;

int ud,lr,start;
int loopx,loopy,endx,endy;
char pic[600][600];
int book[600][600];

int search();
int main(int argc, char const* argv[])
{
    while (cin >> ud >> lr && (ud || lr) ) {
        cin >> start;
        for(int i=0;i<ud;i++)
            for(int j=0;j<lr;j++)
                cin >> pic[i][j];
        int flg=search();
        if(flg)
            cout << book[loopx][loopy]
                 << " step(s) before a loop of "
                 << book[endx][endy]-book[loopx][loopy]+1
                 << " step(s)" << endl;
        else
            cout << book[endx][endy]+1
                 << " step(s) to exit" << endl;
    }
    return 0;
}

int go[4][2]={0,-1,0,1,-1,0,1,0};
int search(){
    memset(book,-1,sizeof(book));
    int oldx,oldy,x,y,cnt=0,flg=0;
    x=0,y=start-1;
    while (1) {
        oldx=x,oldy=y;
        book[oldx][oldy]=cnt++;
        switch(pic[oldx][oldy]){
            case'W':
                y--;
                break;
            case'E':
                y++;
                break;
            case'N':
                x--;
                break;
            case'S':
                x++;
                break;
        }
        if(y>=lr||x<0||x>=ud||y<0){
            endx=oldx,endy=oldy;
            return flg;
        }
        if(book[x][y]!=-1){
            flg=1;
            loopx=x,loopy=y;
            endx=oldx,endy=oldy;
            return flg;
        }
    }
}


//https://vjudge.net/contest/205705#problem/F解
//水题，按着地图走，顺便用book[i][j]=cnt++进行标记
//最后返回终点地址，输出book[i][j]+1即可
//循环的情况类似。
