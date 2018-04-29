#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    while (cin >> n) {
        while (n--) {
            string aim;
            cin >> aim;
            int len_=(int)aim.length(),flg=1;
            for(int i=0;i<len_;i++){
                if(aim[i]!=aim[len_-1-i]){
                    flg=0;break;
                }
                if(i>len_-1-i)break;
            }
            if(flg)cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}
