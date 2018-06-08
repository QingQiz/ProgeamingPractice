// ======================================================================
// Dsp: 黑白棋游戏
// URL: https://www.luogu.org/problemnew/show/P1225
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int pre[100000];
bool vis[1 << 16];

class Status {
protected:
    int status;
    int x1, y1, x2, y2;
    Status **q;
public:
    Status(int status = 0, int l = 0, int r = 0): status(status), q(NULL) {
        // get coordinate
        x1 = ceil(l / 4.0), y1 = l % 4 ? l % 4 : 4;
        x2 = ceil(r / 4.0), y2 = r % 4 ? r % 4 : 4;
    } 

    int showStatus() { return status; }
    void setQueue() { q = new Status*[100000]; }

    void getInit() {
        char c;
        status = 0;
        for (int i = 0; i < 16; ++i) {
            cin >> c;
            status |= int(c - '0');
            status <<= 1;
        }
        status >>= 1;
    }

    // swap the digit on l and r
    int swap(int l, int r) {
        if ((status & (1 << (16 - l))) == (status & (1 << (16 - r)))) return status;
        else return (status ^ ((1 << (16 - l)) | (1 << (16 - r))));
    }

    int getRoot(int nextstatus) {
        setQueue();
        memset(pre, -1, sizeof(pre));
        int l = 1, r = 1;
        q[r++] = this;
        vis[this -> status] = true;
        
        while (l < r) {
            Status *nowstatus = q[l++];
            for (int pos = 1; pos <= 16; ++pos) {
                if (pos % 4) {
                    Status *newstatus = new Status(nowstatus -> swap(pos, pos + 1), pos, pos + 1);
                    if (!vis[newstatus -> status]) {
                        vis[newstatus -> status] = true;
                        q[r++] = newstatus;
                        pre[r - 1] = l - 1;
                        if (newstatus -> status == nextstatus) return r - 1;
                    }
                }
                if (pos <= 12) {
                    Status *newstatus = new Status(nowstatus -> swap(pos, pos + 4), pos, pos + 4);
                    if (!vis[newstatus -> status]) {
                        vis[newstatus -> status] = true;
                        q[r++] = newstatus;
                        pre[r - 1] = l - 1;
                        if (newstatus -> status == nextstatus) return r - 1;
                    }
                }
            }
        }
        return -1;
    }
    void travleback(int pos, int steps = 0) {
        if (pos == 1) {
            printf("%d\n", steps);
            return;
        }
        travleback(pre[pos], steps + 1);
        printf("%d%d%d%d\n", q[pos] -> x1, q[pos] -> y1, q[pos] -> x2, q[pos] -> y2);
    }
};

int main() {
    Status begin, then;
    begin.getInit();
    then.getInit();
    begin.travleback(begin.getRoot(then.showStatus()));
}
// ======================================================================
// Keys: 状压搜索
// 将整个棋盘压缩成为一个二进制的数, 每次交换棋子就相当于交换数的两位
// 当左右的棋子交换时, 相当与第i位与第i+1位交换
// 当上下的棋子交换时, 相当于第i位与第i+4位交换
// 于是枚举交换的位置, 可以得到新的棋盘状态, 以此循环, 即是广搜
// 记录每一个状态的前一个状态, 最后递归输出即可
// ======================================================================
