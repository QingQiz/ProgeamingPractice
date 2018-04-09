#include <functional>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> >queu;
priority_queue<int,vector<int>,less<int> > qued;
int main(int argc, char const* argv[])
{
    int l,r,n;
    while (cin >> l >> r >> n && (l || r || n)) {
        int mid,min=0,max=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&mid);
            ans+=mid;
            if(min<r){
                qued.push(mid);
                min++;
            }
            else {
                if(mid<qued.top()){
                    qued.pop();
                    qued.push(mid);
                }
            }
            if(max<l){
                queu.push(mid);
                max++;
            }
            else {
                if(mid>queu.top()){
                    queu.pop();
                    queu.push(mid);
                }
            }
        }
        while(!queu.empty()){
            ans-=queu.top();
            queu.pop();
        }
        while (!qued.empty()) {
            ans-=qued.top();
            qued.pop();
        }
        printf("%.6lf\n",(double)ans/(n-l-r));
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/G
//方法：
//用优先队列存前l大项和前r小项
