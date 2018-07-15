// ======================================================================
// Dsp: [USACO15DEC]Switching on the Lights 开关灯
// URL: https://www.luogu.org/problemnew/show/P2845#sub
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ======================================================================
#include <iostream>
#include <map>
#include <queue>

using namespace std;

const int maxn = 200000;
struct {
    long long to;
    long long next;
} e[maxn];
map<int, int> head;

void addedge(long long a, long long b, int cnt) {
    e[cnt].to = b;
    e[cnt].next = head[a];
    head[a] = cnt;
}


int n, m;
map<long long, bool> counted, lighted, visited;

inline long long realpos(int x, int y) { return (x - 1) * n + y; }


int bfs() {
    queue<long long> q, reachable;
    lighted[1] = true;
    counted[1] = true;
    q.push(1);
    int finally = 1;
    int mid_ans = 0;
    do {
        mid_ans = 0;
        while(!q.empty()) {
            long long nwp = q.front();
            q.pop();
            if (!visited[nwp]) {
                if (!lighted[nwp]) {
                    reachable.push(nwp);
                    continue;
                }
                for (int i = head[nwp]; i != 0; i = e[i].next) {
                    long long v = e[i].to;
                    lighted[v] = true;
                    if (!counted[v]) {
                        counted[v] = true;
                        mid_ans++;
                    }
                }
                visited[nwp] = true;
            } else continue;
            q.push(nwp + n), q.push(nwp - n);
            if (nwp % n != 0) q.push(nwp + 1);
            if ((nwp - 1) % n != 0) q.push(nwp - 1);
        }
        finally += mid_ans;
        while (!reachable.empty()) {
            q.push(reachable.front());
            reachable.pop();
        }
    } while (mid_ans != 0);
    return finally;
}

int main() {
    cin >> n >> m;
    int x1, y1, x2, y2;
    for (int i = 1; i <= m; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        addedge(realpos(x1, y1), realpos(x2, y2), i);
    }
    cout << bfs() << endl;
}
// ======================================================================
// Keys: 广搜
// 每到一个房间, 开启所有的灯, 然后广搜
// 然后会发现, 原本可达却没有开灯的房间在后面的搜索中灯可能会被打开, 于是
// 这个房间可以打开的灯没有被计算到
// 于是发现可以进行多次广搜, 保证每个灯只被计算一次, 当在某一次搜索时没有
// 打开新的灯, 可以认为搜索结束, 输出计数
// 于是发现需要优化:
//  1. 当一个房间被访问过时, 该房的所有灯被打开, 再次搜索到该房间时, 不需
// 重新开一次灯
// 于是发现还需要进一步优化:
//  2. 记录那些可以到达但是灯位被打开的位置, 每次重新搜索的时候, 直接从这
// 些位置进行搜索, 遇到访问过的位置直接跳过
// ======================================================================
