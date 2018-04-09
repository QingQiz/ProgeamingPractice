#include<bits/stdc++.h>
using namespace std;

int sumof(int X){
    int sum=0;
    do{
        sum+=X%10;
    }while(X/=10);
    return sum;
}

#define maxn 1000000
int primeq[maxn];
int primelist[maxn];
int primenum;

void get_B_prime(){
    memset(primeq,1,sizeof(primeq));
    primeq[0]=primeq[1]=0;
    for(int i=2;i<=maxn;i++){
        if(primeq[i]){
            if(primeq[sumof(i)]){
                primelist[primenum++]=i;
            }
            if(i>=maxn/i)continue;
            for(int j=i*i;j<=maxn;j+=i)
                primeq[j]=0;
        }
    }
}

int main(int argc, char const* argv[])
{

    get_B_prime();
    memset(primeq,0,sizeof(primeq));
    primeq[2]=1;
    for(int i=0;i<primenum;i++){
        primeq[primelist[i]]=1;
    }
    for(int i=1;i<maxn;i++){
        primeq[i]+=primeq[i-1];
    }
    int T;cin >> T;
    int L,R,cnt=0;
    while (T--&&++cnt) {
        cin >> L >> R;
        cout << "Case #" << cnt 
             << ": "     << primeq[R]-primeq[L-1] 
             << endl;
    }
    return 0;
}

//https://vjudge.net/contest/203688#problem/G
//美素数，只要在建立素数表的时候维护一个美素数表，然后再一个数组中标记出美素数的位置
//并建立这个数组的前缀和，对于每次询问，做差即可
