//#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

std::map<char, int> mmp;
const int maxt=100000;

int main(int argc, char const* argv[])
{
    int M,T,U,F,D;
    char c;
    while (cin >> M >> T >> U >> F >> D) {
        int sum=0,ans=0;
        mmp.clear();
        mmp['d']=U+D,mmp['u']=U+D,mmp['f']=F+F;
        for(int i=0;i<T;i++){
            cin >> c;
            sum+=mmp[c];
            if(sum<=M)ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/U
//水题，一直加直到上界即可...
