#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    const string com1=" moveto\n",
                 com2=" lineto\n",
                 inf1="stroke\n",
                 inf2="showpage";
    string data;
    while (cin >> data) {
        int len=data.length();
        int flg1=1,flg2,x=310,y=420;
        cout << x-10 << ' ' << y << com1;
        cout << x << ' ' << y << com2;
        for(int i=0;i<len;i++){
            switch(data[i]){
                case 'V':
                    flg2=1;
                    break;
                case 'A':
                    flg2=-1;
                    break;
            }
            if(flg1==1){
                if(flg2==1) y+=10,flg1=2;
                else y-=10,flg1=-2;
                goto L;
            }
            if(flg1==-1){
                if(flg2==1) y-=10,flg1=-2;
                else y+=10,flg1=2;
                goto L;
            }
            if(flg1==2){
                if(flg2==1) x-=10,flg1=-1;
                else x+=10,flg1=1;
                goto L;
            }
            if(flg1==-2){
                if(flg2==1) x+=10,flg1=1;
                else x-=10,flg1=-1;
                goto L;
            }
L:
            cout << x << ' ' << y << com2;
        }
        cout << inf1 << inf2 << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/C
//看vj上的大佬们都是800字符，而我这个1300字符，实在汗颜。。
//
//题目如果看懂了，就是一道水题
//用两个flg，一个维护正对方向，即上下左右，另一个维护旋转方向
//对于每一个字符进行一次旋转，并记录新的正对方向，维护坐标，即可解决。
