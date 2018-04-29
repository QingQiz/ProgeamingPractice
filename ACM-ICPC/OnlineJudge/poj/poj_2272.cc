#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int getplace(double x,double y){
    double p=x*x+y*y;
    if(p<=9)return 1;
    if(p<=36)return 2;
    if(p<=81)return 3;
    if(p<=144)return 4;
    if(p<=225)return 5;
    else return -1;
}

int getscore(int i){
    switch (i) {
        case 1:
            return 100;
        case 2:
            return 80;
        case 3:
            return 60;
        case 4:
            return 40;
        case 5:
            return 20;
        default:
            return 0;
    }
}

int main()
{
    const string pla=", PLAYER ",
                 sco="SCORE: ",
                 lin=" to ",
                 bal=", TIE.",
                 win=" WINS.";
    while (1) {
        double a,b;
        int sum1=0,sum2=0;
        for(int i=0;i<6;i++){
            cin >> a >> b;
            if(i==0&&a==-100)goto L;
            if(i<3)
                sum1+=getscore(getplace(a,b));
            else
                sum2+=getscore(getplace(a,b));
        }
        int wins=0;
        if(sum1>sum2)wins=1;
        if(sum1<sum2)wins=2;
        if(wins)
            cout << sco << sum1 
                 << lin << sum2 
                 << pla << wins
                 << win << endl;
        else
            cout << sco << sum1
                 << lin << sum2
                 << bal << endl;
    }
L:  return 0;
}

//https://vjudge.net/contest/205705#problem/N
//水题。
