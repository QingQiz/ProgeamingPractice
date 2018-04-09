#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char const* argv[])
{
    int n,flg=0;
    cin >> n;
    stack<int> sta;
    for(long long i=2;i*(i-2)<2*n&&i*(i-1)!=2*n;i++){
        if((n-(i*(i-1)/2))%i==0){
            sta.push((n-(i*(i-1))/2)/i);
            flg=1;
        }
    }
    if(flg){
        while (!sta.empty()) {
            cout << sta.top() << endl;
            sta.pop();
        }
    }
    else cout << "No Solution" << endl;
    return 0;
}

//https://vjudge.net/contest/206616#problem/D
//设数为M=a+(a+1)+(a+2)+...+(a+n-1)
//则,n*a=(M-n*(n-1)/2),当右边能整除n时，存在整数a满足条件，枚举即可
