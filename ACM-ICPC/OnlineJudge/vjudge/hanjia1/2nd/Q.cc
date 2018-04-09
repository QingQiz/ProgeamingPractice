#include <iostream>
#include <algorithm>
using namespace std;

class AC {
public:
    int hp;
    int dps;
    double w;
    bool operator<(const AC L)const{
        if(w!=L.w)
            return L.w<w;
        return hp<L.hp;
    }
    friend istream & operator>>(istream & L,AC & R){
        L >> R.dps >> R.hp;
        R.w=(double)R.dps/R.hp;
        return L;
    }
};

int main(){
    AC data[30];
    int s_[30],n;
    while (cin >> n) {
        for(int i=0;i<n;i++)
            s_[i]=0;
        for(int i=0;i<n;i++)
            cin >> data[i];
        sort(data,data+n);
        s_[n-1]=data[n-1].dps;
        for(int i=n-2;i>=0;i--){
            s_[i]=data[i].dps+s_[i+1];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=data[i].hp*s_[i];
        }
        cout << sum << endl;
    }
}

//https://vjudge.net/contest/205706#problem/Q
//攻击越高,血量越少的敌人应该首先被杀死
