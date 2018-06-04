// ============================================================
// Dsp: Sramoc问题
// URL: https://www.luogu.org/problemnew/show/P1602
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int k, m;

struct Num {
    int mod;
    string num;

    Num(int mod, int i = 0): mod(mod) {num = char(i + '0');}

    Num newNum(int mod, int lastBit) {
        Num ret(mod);
        ret.num = num + char(lastBit + '0');
        return ret;
    }
};
queue<Num> q;
bool exits[1000];

int main() {
    cin >> k >> m;
    for (int i = 1; i < k; ++i) {
        if (i % m == 0) {
            cout << i << endl;
            return 0;
        } else {
            q.push(Num(i % m, i));
            exits[i % m] = true;
        }
    }
    while (!q.empty()) {
        Num tmp = q.front();
        q.pop();
        for (int i = 0; i < k; ++i) {
            int nmod = tmp.mod * 10 + i;
            nmod %= m;
            if (exits[nmod]) continue;
            exits[nmod] = true;
            if (nmod == 0) {
                cout << tmp.newNum(nmod, i).num << endl;
                return 0;
            }
            q.push(tmp.newNum(nmod, i));
        }
    }
}
// ============================================================
// Keys: 广搜
// 用a<>b|c 表示a,b模c同余
// 因为 a<>ma|m, b<>mb|m, 则10a+b<>10ma+mb<>(10ma+mb)%m|m
// 因此可以枚举所有数向已知数的后面添加, 即若a%m!=0, 则枚举b,
// 得到新的数ab, 算出ab%m, 若不等于0, 令a=ab,重复上述步骤, 直到
// 余数为零, 则得到最小值

// 搜索剪枝: 
// 若搜索途中出现 a<>b|m 则在后续步骤中往a b后面添加新的数时,
// a b表现出来的性质完全相同, 因此剪掉a b中较大的数, 表现在广搜
// 中为剪掉a b中后出现的数
// ============================================================
