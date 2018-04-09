#include <iostream>
#include <stack>
using namespace std;

int ans(int n){
    if(n==1)return 2;
    else return 8*(n-1)+1+ans(n-1);
}

int main(int argc, char const* argv[])
{
    int t;
    cin >>t;
    while (t--) {
        int n;
        cin >> n;
        cout << ans(n)-n+1 << endl;
    }
    return 0;
}

//https://vjudge.net/contest/206616#problem/E
//每多一个四边形多8*n个交点，多8n+1个面，带一下数据，减n-1,得到答案...
