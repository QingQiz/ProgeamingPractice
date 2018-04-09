//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

class jf{
public:
    int j;
    int f;
    double w;
    friend istream & operator>>(istream & is,jf & R){
        is >> R.j >> R.f;
        R.w=(double)R.j/R.f;//获取一单位猫粮换的javabean的个数
        return is;
    }
    bool operator<(const jf L)const{
        return w>L.w;//降序排列规则
    }
};

int main(int argc, char const* argv[])
{
    int sum,n;
    while (cin >> sum >> n &&(sum+1 || n+1)) {
        jf *data=new jf[n];
        for(int i=0;i<n;i++){
            cin >> data[i];
        }
        sort(data,data+n);
        double ans=0;
        for(int i=0;i<n;i++){
            if(sum>=data[i].f){//贪心
                ans+=data[i].j;
                sum-=data[i].f;
            }
            else{//贪心
                ans+=data[i].w*sum;
                sum=0;
            }
            if(sum==0)break;
        }
        printf("%.3lf\n",ans);
        delete [] data;
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/E
//贪心，
//
//贪心策略试证:
//贪心策略:每次选择单位猫粮(F)能换取最多的javabean(J)的房间进行交换,直到该房间J(重复上述操作),或手中无F(结束)
//设该策略为A且不是最优策略,设第i个房间每单位F,能换wi单位J(wi=Ji/Fi),设每次选则一单位的F来换取相应数量的J,设用A(k)表示策略A在第k次选择时获得的J
//设最最优方案为O,且在第k次开始出现与A不同的选择,即O(k)!=A(k)且当i<k时O(i)==A(i),
//则设方案O'在前k次(包含第k次)的选择上与A相同,其余的选择上与O相同,
//则O'仅再第k次选择上与O不同,
//则根据贪心策略,w(ak)>=w(ok),即O'(k)>=O(k),
//即O'是比O更优的方案,这与O是最优方案矛盾,
//所以假设错误,
//所以A方案为最优方案.
