#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,l;
    cin >> n >> l;
    int *dat =new int[n];
    for(int i=0;i<n;i++)
        cin >> dat[i];
    sort(dat,dat+n);
    int ans=0;
    for(int i=n-1,j=0;i>=j;){
        if(dat[i]+dat[j]<=l){
            i--;
            j++;
            ans++;
        }
        else{
            i--;
            ans++;
        }
    }
    cout << ans << endl;
}

//https://vjudge.net/contest/205706#problem/U
//贪心
