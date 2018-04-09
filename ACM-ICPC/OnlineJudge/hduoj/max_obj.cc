#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[])
{
    char str[100];
    while (cin.getline(str,99)) {
        str[strlen(str)]='\0';
        char c='\0';
        for(int i=0;i<(int)strlen(str);i++)
            if(str[i]>c)c=str[i];
        for(int i=0;i<(int)strlen(str);i++){
            if(str[i]!=c)
                cout << str[i];
            else {
                cout << str[i]; 
                cout << "(max)";
            }
        }
        cout << endl;
    }
    return 0;
}
