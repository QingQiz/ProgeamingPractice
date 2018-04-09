#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class AC{
public:
    string dat;
    int n;
    friend istream & operator>>(istream & L,AC & R){
        L >> R.dat;
        R.n=0;
        int len=R.dat.length();
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(R.dat[i]>R.dat[j])
                    R.n++;
            }
        }
        return L;
    }
    bool operator<(const AC L)const{
        return n<L.n;
    }
};
int main()
{
    int m,n;
    cin >> n >> m;
    AC *data=new AC[m];
    for(int i=0;i<m;i++){
        cin >> data[i];
    }
    sort(data,data+m);
    for(int i=0;i<m;i++){
        cout << data[i].dat << endl;
    }
    delete [] data;
    return 0;
}

//https://vjudge.net/contest/205706#problem/J
//水题
//求出每个字符串的逆序数,排序即可
