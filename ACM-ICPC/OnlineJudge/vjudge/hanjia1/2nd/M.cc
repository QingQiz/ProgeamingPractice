#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=2e7;
bool primeq[maxn+1];
vector<int>primelist;
int primenum;

void getprime(){
    memset(primeq,true,sizeof(primeq));
    for(int i=2;i<maxn;i++){
        if(primeq[i]){
            primelist.push_back(i);
            if(i>=maxn/i)continue;
            for(int j=i*i;j<=maxn;j+=i)
                primeq[j]=false;
        }
    }
    primeq[0]=primeq[1]=false;
    primenum=primelist.size();
}

int main(int argc, char *argv[])
{
    getprime();
    int t,a,b,cnt=0,ans;
    cin >> t;
    while(t--){
        ans=-1;
        cin >> a >> b;
        if(a>b)
            a^=b^=a^=b;
        int cmp=b-a;//一定要先做差，不然这个差会在进行比较时被连续重复做上上百万次，从而超时
        for(int i=1;i<primenum;i++){
            if(primelist[i]-primelist[i-1]==cmp && primelist[i-1]>=a){
                ans=primelist[i]-b;
                break;
            }
        }
        cout << "Case " << ++cnt
             << ": "    << ans   << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/M
//
//水题
//数组开大点，，从未开过上千万的数组......
//TE的原因见注释
//WA的原因，没有比较素数和a、b的大小从而出现对诸如3,6的误判
