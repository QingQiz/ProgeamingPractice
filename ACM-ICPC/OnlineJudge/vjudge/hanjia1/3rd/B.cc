#include <iostream>
#include <string>
#include <queue>
using namespace std;
class AC{
public:
    int ID;
    int gap;
    int start;
    bool operator<(const AC C)const {
        if(start != C.start) {
            return start > C.start;
        }
        return ID > C.ID;
    }
};
int main(){
    int sum;
    string mid;
    priority_queue<AC>q;
    while (1) {
        AC itl;
        cin >> mid;
        if(mid[0]=='#')break;
        cin >> itl.ID >> itl.gap;
        itl.start=itl.gap;
        q.push(itl);
    }
    cin >> sum;
    while (sum--) {
        AC itl=q.top();
        cout << itl.ID << endl;
        itl.start+=itl.gap;
        q.pop();
        q.push(itl);
    }
    return 0;
}

// https://vjudge.net/contest/205707#problem/B
// 优先队列
// 起始输出时间是间隔时间
// 输出队列优先级最高的元素,
// 然后对队顶元素处理后重新入队
// 即,下次输出的时间是这次输出时间加间隔时间
