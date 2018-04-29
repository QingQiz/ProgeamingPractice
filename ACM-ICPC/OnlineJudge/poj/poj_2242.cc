#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define PI 3.141592653589793

double distance(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(int argc, char const* argv[])
{
    double x1,y1,x2,y2,x3,y3;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        double a,b,c;
        a=distance(x1,y1,x2,y2);
        b=distance(x1,y1,x3,y3);
        c=distance(x2,y2,x3,y3);
        double p=(a+b+c)/2.0;
        double s=sqrt(p*(p-a)*(p-b)*(p-c));
        double r=(a*b*c)/(4.0*s);
        printf("%.2lf\n",2*PI*r);
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/W
//
//水题，就是写起来有些无聊
//
//记住公式：
//R=abc/(4S)    S由海伦公式得到
