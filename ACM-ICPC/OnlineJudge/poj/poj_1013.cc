//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int flg[12];
int main()
{
    string a,b,c;
    int t;cin >> t;
    while (t--) {
        memset(flg,0,sizeof(flg));
        for(int i=0;i<3;i++){
            cin >> a >> b >> c;
            int len=a.length();
            if(c=="even"){
                for(int i=0;i<len;++i){
                    flg[a[i]-'A']=10;
                    flg[b[i]-'A']=10;
                }
            }
            else if(c=="up"){
                for(int i=0;i<len;++i){
                    if(flg[a[i]-'A']!=10)
                        flg[a[i]-'A']++;
                    if(flg[b[i]-'A']!=10)
                        flg[b[i]-'A']--;
                }
            }
            else if(c=="down"){
                for(int i=0;i<len;++i){
                    if(flg[a[i]-'A']!=10)
                        flg[a[i]-'A']--;
                    if(flg[b[i]-'A']!=10)
                        flg[b[i]-'A']++;
                }
            }
        }
        int pla,max=0;
        for(int i=0;i<12;i++){
            if(flg[i]==10)continue;
            if(max<abs(flg[i])){
                max=abs(flg[i]);
                pla=i;
            }
        }
        cout << char('A'+pla) << " is the counterfeit coin and it is "
             << (flg[pla]>0?"heavy.":"light.") << endl;
    }
    return 0;
}


//----------------------------------------------------------------------------------
//https://vjudge.net/contest/205705#problem/S                                      | 
//----------------------------------------------------------------------------------
//通过天平的测量结果判断真假硬币                                                   |
//                                                                                 |
//对于所有硬币，开始时用0来标记，                                                  |
//如果测量结果是even，可以断定两边都是真的，后继判断都可以跳过两边出现过的硬币，   |
//对于这些硬币，用10来标记它们。                                                   |
//                                                                                 |
//如果结果是up，则怀疑左边的轻而右边的重，down反之，                               |
//                                                                                 |
//被怀疑重的标记++，轻的反之，最后对除过标记为10的进行怀疑次数的判断，即标记的绝对值
//被怀疑次数最多的就是假币，标记为正，则重，反之，则轻                             |
//(因为此题最多判断3次，所以真用10标记，如果判断次数较多可置真为INF)               |
//----------------------------------------------------------------------------------

