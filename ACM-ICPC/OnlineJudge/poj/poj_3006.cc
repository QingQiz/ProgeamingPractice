#include <iostream>
#include <cstring>
using namespace std;

const int maxn=1e6+10;
bool primelist[maxn];

void getprime(){
    memset(primelist,true,sizeof(primelist));
    primelist[0]=primelist[1]=false;
    for(int i=2;i<=maxn/i;i++){
        if(primelist[i]){
            for(int j=i*i;j<=maxn;j+=i)
                primelist[j]=false;
        }
    }
}

int main() {
    getprime();
    int a,d,n;
    while (cin >> a >> d >> n && (a || d || n)) {
        int sum=0,cmp=a;
        while (1) {
            if(primelist[cmp])sum++;
            if(sum==n)break;
            cmp+=d;
        }
        cout << cmp << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/O
//
//求等差数列第n个素数
//水题，打一个素数表，快的飞起
