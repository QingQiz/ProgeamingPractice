#include <bits/stdc++.h>
using namespace std;
struct data{
    double data;
    int place;
};
bool cmp(data a,data b){
    return a.data>b.data;
}

bool cmp2(data a,data b){
    return a.place>b.place;
}

int main(int argc, char const* argv[])
{
    int N,M,K;
    while (cin >> N >> M >> K) {
        data *ans=new data[M];
        double mid;
        for(int i=0;i<M;i++)
            ans[i].data=0,ans[i].place=i+1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> mid;
                ans[j].data+=mid;
            }
        }
        sort(ans,ans+M,cmp);
        sort(ans,ans+K,cmp2);
        for(int i=0;i<K;i++){
            if(i)cout << ' ';
            cout << ans[i].place;
        }
        cout << endl;
        delete [] ans;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/H
//
//练习sort的题
//建立结构题，写一个排序函数，水题
//
//先总体排序，再为要输出的数据进行另外的排序
