#include <iostream>
#include <string>
#include <stack>
using namespace std;
string l, r, ans;
string::iterator lit, rit;
void solve(stack<char> & dat){
    if(rit==r.end()){
        cout << ans << endl;
        return ;
    }
    if(lit!=l.end()){
        dat.push(*lit);
        lit++;
        ans+="i ";
        solve(dat);
        ans.erase(ans.end()-1);
        ans.erase(ans.end()-1);
        lit--;
        dat.pop();
    }
    if(!dat.empty()){
        char c=dat.top();
        if(c==*rit){
            dat.pop();
            ans+="o ";
            rit++;
            solve(dat);
            ans.erase(ans.end()-1);
            ans.erase(ans.end()-1);
            rit--;
            dat.push(c);
        }
    }
}

int main(){
    stack<char> dat;
    while (cin >> l >> r) {
        cout << '[' << endl;
        if(l.length()==r.length()){
            lit = l.begin();
            rit = r.begin();
            solve(dat);
        }
        cout << ']' << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/Y
