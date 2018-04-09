#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char _,char __){
    return _>__;
}

int f(char a,char b,char c,char d,char e){
    int A[5];
    A[0]=a-'A'+1,A[1]=b-'A'+1,A[2]=c-'A'+1,
        A[3]=d-'A'+1,A[4]=e-'A'+1;
    return A[0]-
           A[1]*A[1]+
           A[2]*A[2]*A[2]-
           A[3]*A[3]*A[3]*A[3]+
           A[4]*A[4]*A[4]*A[4]*A[4];
}

int main(void)
{
    int tar;
    char dat[13];
    while(cin >> tar >> dat){
        if(tar==0 && strcmp(dat,"END")==0)break;
        int len=strlen(dat);
        sort(dat,dat+len,cmp);
        for(int a=0;a<len;a++){
            for(int b=0;b<len;b++){
                if(b==a)continue;
                for(int c=0;c<len;c++){
                    if(c==b || c==a)continue;
                    for(int d=0;d<len;d++){
                        if(d==a || d==b || d==c)continue;
                        for(int e=0;e<len;e++){
                            if(e==a || e==b || e==c || e==d)continue;
                            if(f(dat[a],dat[b],dat[c],dat[d],dat[e])==tar){
                                cout << dat[a] << dat[b] << dat[c] << dat[d] << dat[e] << endl;
                                goto L;
                            }
                        }
                    }
                }
            }
        }
        cout << "no solution\n";
L:      ;
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/I
//暴力枚举，最多枚举12^5次，不会超时
