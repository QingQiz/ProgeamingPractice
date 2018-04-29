#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(a^=b^=a^=b%=a);
    return b;
}

int ex_gcd(int a,int b,int & x,int & y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    else {
        int r=ex_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}

int main(int argc, char const* argv[])
{
    int a,b;
    while (cin >> a >> b) {
        int x,y;
        if(gcd(a,b)!=1){
            cout << "sorry" << endl;
            goto L;
        }
        else{
            ex_gcd(a,b,x,y);
            while (x>0) {
                x-=b;
                y+=a;
            }
            while (x<0) {
                x+=b;
                y-=a;
            }
        }
        cout << x << ' ' << y << endl;
L:
        ;
    }
    return 0;
}

// https://vjudge.net/contest/203688#problem/A
// 即是解方程 ax+by=1的最小整数解，裸题。
