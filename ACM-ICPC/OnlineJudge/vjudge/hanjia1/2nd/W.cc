#include <iostream>
#include <queue>
using namespace std;

class ty{
public:
    int plc;
    int size;
    bool operator<(const ty & L)const &{
        if(L.plc!=plc)
            return plc>L.plc;
        return L.size<size;
    }
    friend istream & operator>>(istream & L,ty & R){
        L >> R.plc >> R.size;
        return L;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ty dat;
        priority_queue<ty>que;
        for(int i=0;i<n;i++){
            cin >> dat;
            que.push(dat);
        }
        int cnt=0,ans=0;
        while (!que.empty()) {
            if((++cnt)&1){
                ty mid=que.top();
                que.pop();
                mid.plc+=mid.size;
                que.push(mid);
            }
            else {
                ans=que.top().plc;
                que.pop();
            }
        }
        cout << ans << endl;
    }
    return 0;
}

//https://vjudge.net/contest/205706#problem/W
//拟定优先度,位置在前的优先,大的(扔的远的)优先,创建优先队列
//将所有数据插入优先队列,根据规则改变元素属性,奇数个改变后push,pop,偶数个直接pop,最后一个pop的
//的位置就是答案
