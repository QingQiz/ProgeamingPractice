#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[])
{
    int n;
    const int cmp[6]={
        100,50,10,5,2,1
    };
    while (cin >> n && n) {
        int ans=0,mon;
        for (int i = 0; i < n; i++) {
            cin >> mon;
            while(mon!=0){
                for(int i=0;i<6;i++)
                    if(cmp[i]<=mon){
                        ans++,mon-=cmp[i];
                        break;
                    }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
