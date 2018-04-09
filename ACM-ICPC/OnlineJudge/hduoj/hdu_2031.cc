#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[])
{
    std::map<int, char> mm;
    std::stack<char> ans;
    for(int i=0;i<10;i++)
        mm[i]='0'+i;
    for(int i=10;i<=16;i++)
        mm[i]='A'+i-10;
    int m,base;
    while (cin >> m >> base) {
        if(m<0)cout << '-';
        m=m>0?m:-m;
        do{
            ans.push(mm[m%base]);
        }
        while(m/=base);

        while (!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}
