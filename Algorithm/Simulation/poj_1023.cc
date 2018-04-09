#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(int argc, char const* argv[])
{
    int T;cin >> T;
    while (T--) {
        long long n;
        int funx,roo;
        string rul;
        cin >> roo >> rul >> n;
        funx=roo;
        char *ans=new char [funx];
        memset(ans,'\0',funx*sizeof(char));
        while (funx--) {
            if(n&1){
                if(rul[funx]=='p'){
                    ans[funx]='1';
                    n=(n-1)>>1;
                }
                else {
                    ans[funx]='1';
                    n=(n+2)>>1;
                    //给最后一位取1,数字少了一个2...
                    //给最后一位取0,数字少了一个1...
                    //前者可以，后者却是不行...
                }
            }
            else {
                ans[funx]='0';
                n>>=1;
            }
        }
        if(n!=0)
            cout << "Impossible" << endl;
        else {
            for(int i=0;i<roo;i++){
                if(ans[i]=='\0')continue;
                cout << ans[i];
            }
            cout << endl;
        }
        delete [] ans;
    }
    return 0;
}

//https://vjudge.net/contest/205705#problem/V
//
//算是水题吧，注意数据范围，要用longlong
//对于目标数字进行分解，
//若对象是偶数分解得到0,则无论n，p
//若对象是奇数分解得到1,则
//      当是p的时候，与正常情况无二，
//      当是n的时候，则相当于给原数字减了一个2,因此需要加上2
