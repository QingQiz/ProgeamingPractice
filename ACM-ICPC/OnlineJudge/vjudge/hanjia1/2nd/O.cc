#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=50000;
ll bits[maxn];
ll s_bits[maxn];

void getdata(){
    bits[1]=1,s_bits[1]=1;
    for(int i=2;i<maxn;i++){
        bits[i]=bits[i-1]+(int)log10((double)i)+1;
        s_bits[i]=s_bits[i-1]+bits[i];
    }
}

int main(){
    getdata();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k=-1;
        for(int i=1;i<maxn;i++){
            if(s_bits[i]>=n){
                k=i;
                break;
            }
        }
        n-=s_bits[k-1];
        int pos=-1;
        for(int i=1;i<=k;i++){
            n-=(int)log10((double)i)+1;
            if(n<=0){
                pos=i;
                break;
            }
        }
        n+=(int)log10((double)pos)+1;
        int poss=(int)log10((double)pos)+1-n;
        while(poss-->0){
            pos/=10;
        }
        cout << pos%10 << endl;
    }
    return 0;
}

// https://vjudge.net/contest/205706#problem/O
// 先打表列出每组数列的长度和前缀和
// 用前缀和判断输入的数属于第几个数列
// 再判断输入的数属于该数列中的第几个数
// 再判断属于该数的第几位
// 输出这一位
