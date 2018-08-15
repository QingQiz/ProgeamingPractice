// ============================================================
// Dsp: 
// URL: http://poj.org/problem?id=2367
// Author: Sofee ( _s@mail.nwpu.edu.cn )
// ============================================================
#include <iostream>
#include <list>
#include <queue>

using std::cin;
using std::cout;
using std::list;
using std::queue;

class Graph {
private:
    int v;                  // 节点总数
    list<int> * ob;         // 邻接表
    queue<int> q;           // 所有入度为0的节点
    int * indegree;         // 所有结点的入度
public:
    Graph(int);             // 构造函数
    ~Graph();               // 析构函数
    void insert(int, int);  // 插入节点
    bool topoSort();        // 拓扑排序
};

Graph::Graph(int __v) {
    v = __v;
    ob = new list<int>[__v];
    indegree = new int[__v];
    for (int i = 0; i < __v; ++i) {
        indegree[i] = 0;
    }
}

Graph::~Graph() {
    delete [] ob;
    delete [] indegree;
}

void Graph::insert(int __u, int __v) {
    ob[__u].push_back(__v);
    ++indegree[__v];
}

bool Graph::topoSort() {
    for (int i = 0; i < v; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int nowv = q.front();
        q.pop();

        cout << nowv + 1 << ' ';
        ++cnt;
        for (list<int>::iterator i = ob[nowv].begin(); i != ob[nowv].end(); ++i) {
            if (--indegree[*i] == 0)
                q.push(*i);
        }
    }
    if (cnt == v) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    Graph g(n);
    for (int i = 0; i < n; ++i) {
        int mid;
        while (1) {
            cin >> mid;
            if (mid == 0) break;
            g.insert(i, mid - 1);
        }
    }
    g.topoSort();
    cout << '\n';
    return 0;
}
// ============================================================
// 拓扑排序的裸题
// ============================================================
