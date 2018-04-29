#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        int ans[5];
        string str;
        getline(cin,str);
        memset(ans,0,sizeof(ans));
        for (int i = 0; i < (int)str.length(); i++) {
            if(str[i]=='a')ans[0]++;
            if(str[i]=='e')ans[1]++;
            if(str[i]=='i')ans[2]++;
            if(str[i]=='o')ans[3]++;
            if(str[i]=='u')ans[4]++;
        }
        cout << 'a' << ':' << ans[0] << endl;
        cout << 'e' << ':' << ans[1] << endl;
        cout << 'i' << ':' << ans[2] << endl;
        cout << 'o' << ':' << ans[3] << endl;
        cout << 'u' << ':' << ans[4] << endl;
        if(n)cout << endl;
    }
    return 0;
}
