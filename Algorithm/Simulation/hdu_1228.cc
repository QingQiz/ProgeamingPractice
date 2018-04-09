#include <bits/stdc++.h>
using namespace std;
#define maxn 1000001

const string data[]={
    "zero","one","two", "three",
    "four","five","six", "seven",
    "eight", "nine"
};

int main()
{
    std::map<string, int> mm;
    for(int i=0; i<10; i++)
        mm[data[i]]=i;
    string le, ri, mid;
    while (1) {
        int a, b;
        cin >> le >> mid;
        if(mid=="+") {
            cin >> ri >> mid;
            if(mid=="=") {
                if(mm[le]==0&&mm[ri]==0)break;
                cout << mm[le]+mm[ri];
            }
            else{
                b=mm[ri]*10+mm[mid];
                cin >> mid;
                cout << mm[le]+b;
            }
        }
        else{
            a=mm[le]*10+mm[mid];
            cin >> mid >> ri >> mid;
            if(mid=="=")
                cout << mm[ri]+a;
            else {
                b=mm[ri]*10+mm[mid];
                cin >> mid;
                cout << a+b;
            }
        }
        cout << endl;
    }
}

//https://vjudge.net/contest/205705#problem/E
//水题，字符串，顺便练习map
