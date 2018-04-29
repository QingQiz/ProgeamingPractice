#include <bits/stdc++.h>
#define MAX 1000
#define SETZ(_) memset(_,0,sizeof(_))
#define LEN(_) (int)(_.length())
#define TRA(_,__) {\
    int len=__.length();\
    for(int i=0;i<len;i++)\
        _[MAX-1-i]=__[len-1-i]-48;\
}

#define DISPLAY(_) {\
    int __=0;\
    while(_[__++]==0);\
    for(--__;__<MAX;__++)cout << _[__];\
}

void pluss(int * a,int * b,int * ans){
    for(int i=0;i<MAX;i++)
        ans[i]=a[i]+b[i];
    for(int i=MAX-1;i>=0;i--){
        ans[i-1]+=ans[i]/10;
        ans[i]%=10;
    }
}

int main() {
    using namespace std;
    string str1,str2;
    int T,cont=0;
    cin >> T;
    while(T--){
        cin >> str1 >> str2;
        int a[MAX],b[MAX],ans[MAX];
        SETZ(a);SETZ(b);SETZ(ans);
        TRA(a,str1);
        TRA(b,str2);
        pluss(a,b,ans);
        cout << "Case " << ++cont << ':' << endl; 
        DISPLAY(a);
        cout << " + ";
        DISPLAY(b);
        cout << " = ";
        DISPLAY(ans);
        cout << endl;
        if(T!=0)cout << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/Z
//大数加法......
