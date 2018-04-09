#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn=1e5;
vector<int>primelist;
int primenum;
bool primeq[maxn+1];
void getprime(){
    memset(primeq,true,sizeof(primeq));
    for(int i=2;i<maxn;i++){
        if(primeq[i]){
            primelist.push_back(i);
            if(i>maxn/i)continue;
            for(int j=i*i;j<maxn;j+=i){
                primeq[j]=false;
            }
        }
    }
    primeq[0]=primeq[1]=false;
    primenum=primelist.size();
}
int getfac(int n){
    int ans=1;
    int now=n;
    for(int i=0;i<primenum && primelist[i]<=n/primelist[i];i++){
        int mid=0;
        if(now%primelist[i]==0){
            while (now%primelist[i]==0) {
                now/=primelist[i];
                mid++;
            }
            ans*=(mid+1);
        }
    }
    if(now!=1){
        ans*=2;
    }
    return ans;
}
int main(){
    getprime();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans=getfac(n-1);
        cout << ans << endl;
    }
}
