#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string sss;
        getline(cin,sss);
        int len_=(int)sss.length(),sum=0;
        for (int i = 0; i < len_; i++) {
            if(isalnum(sss[i])||iscntrl(sss[i])||
                    ispunct(sss[i])||isspace(sss[i]));
            else sum++;
        }
        cout << sum/2 << endl;
    }
    return 0;
}
