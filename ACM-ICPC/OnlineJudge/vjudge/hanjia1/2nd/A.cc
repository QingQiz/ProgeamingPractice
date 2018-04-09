#include <bits/stdc++.h>
using namespace std;

map<string,int> mmp;
map<string,int>::iterator it;

int main(int argc, char const* argv[])
{
    int n;
    while (cin >> n && n) {
        mmp.clear();
        string s;
        while (n--) {
            cin >> s;
            mmp[s]++;
        }
        map<string,int>::iterator ans=mmp.begin();
        //auto ans=mmp.begin();
        for(it=mmp.begin();it!=mmp.end();it++){
            if(ans->second<it->second)ans=it;
        }
        cout << ans->first << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/A
//
//map的水题，不用map还挺麻烦的
