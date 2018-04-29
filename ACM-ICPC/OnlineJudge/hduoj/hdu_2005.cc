#include <bits/stdc++.h>
#define swap(a,b) ((a)=(a)^(b),(b)=(a)^(b),(a)=(a)^(b))
#define DISTANCE(_,__) \
    (_.x-__.x)*(_.x-__.x)+(_.y-__.y)*(_.y-__.y)
#define PI acos(-1)
#define abs(_) (_)>0?(_):(-_)

int main(int argc, char const* argv[])
{
    using namespace std;
    int days[12]={
        31,28,31,30,31,30,31,31,30,31,30,31
    };
    int y,m,d;
    while(~scanf("%d%*c%d%*c%d",&y,&m,&d)){
        int ans=0;
        for(int i=0;i<m-1;i++)ans+=days[i];
        ans+=d;
        if((m>2)&&((!(y%4)&&(y%100))||(!(y%100)&&!(y%400))))
            ans+=1;
        cout << ans << endl;
    }
    return 0;
}
