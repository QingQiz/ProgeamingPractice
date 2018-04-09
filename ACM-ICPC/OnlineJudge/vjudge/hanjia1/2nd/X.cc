#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
#define Empty(_) \
    while(!_.empty())\
        _.pop()

stack<int> sta;
queue<string> ans;
int fun(string,string,int);
int main(int argc, char const* argv[])
{
    int n;
    while(cin >> n){
        Empty(sta);
        Empty(ans);
        string IN,OUT;
        cin >> IN >> OUT;
        if(fun(IN,OUT,n)){
            cout << "Yes." << endl;
            while (!ans.empty()) {
                cout << ans.front() << endl;
                ans.pop();
            }
        }
        else
            cout << "No." << endl;
        cout << "FINISH" << endl;
    }
    return 0;
}

int fun(string in,string out,int n){
    int i=0,j=0;        
    while(i<n){
        if(in[i]!=out[j]){
            sta.push(in[i]);
            ans.push("in");
        }
        else {
            ans.push("in");
            ans.push("out");
            j++;
            while(!sta.empty()){
                if(sta.top()==out[j]){
                    sta.pop();
                    ans.push("out");
                    j++;
                }
                else break;
            }
        }
        i++;
    }
    if(sta.empty())return 1;
    return 0;
}

//https://vjudge.net/contest/205706#problem/X
//火车进站问题，在判断的时候顺便用队列记录判断过程
//可以达成，直接输出队列即可。
//
