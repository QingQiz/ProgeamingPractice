#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct mmp{
    int tmp=0;
    int now=0;
};

int chg_jud(mmp data[],int n,int & sum){
    int flg=1;
    for(int i=1;i<n;i++){
        data[i].tmp+=data[i-1].now/2;
        data[i-1].now/=2;
    }
    data[0].tmp+=data[n-1].now/2;
    data[n-1].now/=2;
    for(int i=0;i<n;i++){
        data[i].now+=data[i].tmp,data[i].tmp=0;
        if(data[i].now&1)data[i].now++;
        if(i>0&&data[i].now!=data[i-1].now)flg=0;
    }
    sum++;
    return flg;
}

int main() {
    int n;
    while (cin >> n && n) {
        mmp *data=new mmp [n];
        int sum=0,flg=1;
        for(int i=0;i<n;i++){
            cin >> data[i].now;
            if(i>0&&data[i].now!=data[i-1].now)flg=0;
        }
        if(flg){
            cout << '0' << endl;
            continue ;
        }
        while(!chg_jud(data,n,sum));
        cout << sum << ' ' << data[0].now << endl;
        delete [] data;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/B
//题中要求将每个成员的一半加给下一个成员并且同时进行，即要求将原来的值和新加上的值
//分别存储，使用结构题可以完美解决。
