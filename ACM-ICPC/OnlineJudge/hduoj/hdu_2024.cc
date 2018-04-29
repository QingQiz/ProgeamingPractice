#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    while (cin >> n) {
        cin.ignore();
        string aim;
        while (n--) {
            int flg=1;
            getline(cin,aim);
            if(isalpha(aim[0])||aim[0]=='_'){
                for(int i=0;i<(int)aim.length();i++)
                    if(!(isalnum(aim[i])||aim[i]=='_')){
                        flg=0;break;
                    }
            }
            else flg=0;
            if(flg)cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}
