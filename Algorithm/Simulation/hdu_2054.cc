#include <bits/stdc++.h>
using namespace std;

char a[110000],b[110000];

void getrel(char s[]){
    int len=strlen(s);
    int flg=0;
    for(int i=0;i<len;i++)
        if(s[i]=='.'){
            flg=1;break;
        }
    if(flg){
        for(int i=len-1;i>=0;i--){
            if(s[i]=='0')
                s[i]='\0';
            else break;
            len--;
        }
        if(s[len-1]=='.'){
            s[len-1]='\0';
        }
    }
}

int main(int argc, char const* argv[])
{
    while (cin >> a >> b) {
       getrel(a);getrel(b);
       if(strcmp(a,b))
           cout << "NO" << endl;
       else 
           cout << "YES" << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/Y
//本以为是水题，没想到确实是水题，不过要用到字符串
//再有，注意到1=1.0000000,则此题可解。
