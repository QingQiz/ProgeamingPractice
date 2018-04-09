#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[])
{
    string str;
    while (getline(cin,str)) {
        for(int i=0;i<(int)str.length();i++){
            if(i==0)
                str[i]=toupper(str[i]);
            else if(str[i]==' ')
                str[i+1]=toupper(str[i+1]);
        }
        cout << str << endl;
    }
    return 0;
}
