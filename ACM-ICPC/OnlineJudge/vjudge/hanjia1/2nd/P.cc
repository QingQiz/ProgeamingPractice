#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

class sol{
public:
    int reduce;
    int deadline;
    bool operator<(const sol L)const{
        if(L.reduce!=reduce)
            return L.reduce<reduce;
        else return deadline<L.deadline;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        sol *dat=new sol[n];
        for(int i=0;i<n;i++){
            cin >> dat[i].deadline;
        }
        for(int i=0;i<n;i++){
            cin >> dat[i].reduce;
        }
        sort(dat,dat+n);
        int sum=0;
        map<int,int>mmp;
        mmp.clear();
        for(int i=0;i<n;i++){
            if(mmp[dat[i].deadline]==0)
                mmp[dat[i].deadline]++;
            else {
                int cmp=dat[i].deadline-1;
                int flg=1;
                while(cmp>0){
                    if(mmp[cmp]==0){
                        mmp[cmp]++;
                        flg=0;
                        break;
                    }
                    cmp--;
                }
                if(flg)sum+=dat[i].reduce;
            }
        }
        cout << sum << endl;
        delete [] dat;
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/P
//贪心
//
//对于所有的作业以扣分最多为依据进行排序，
//策略：在作业期限的最后一天做该作业
//如果这一天被占用，则占用这一天的作业扣分一定比想要安排进去的多
//则将该作业向前推一天，如果没有找到可以安排的日子，则扣掉该作业的分数
