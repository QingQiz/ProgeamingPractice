#include <iostream>
#include <cmath>
using namespace std;
int power(int n,int di){
    int pie=log10((double)n)+1;
    int ans=1;
    for(int i=0;i<pie;i++)
        ans*=di;
    return ans;
}
int jud(int n){
    int sum=0;
    int mid=n;
    do{
        int aa=mid%10;
        sum+=power(n,aa);
    }while(mid/=10);
    if(sum==n)return 1;
    return 0;
}

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    for(int i=n;;i++){
        if(jud(i)){
            cout << i << endl;
            break;
        }
    }
    return 0;
}

//https://vjudge.net/contest/206616#problem/B
//水题，注意水仙花数的定义
//（int)log10(n)+1是一个数的位数
