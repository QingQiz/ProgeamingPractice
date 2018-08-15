#include <iostream>
#include <vector>
#include <cstdio>
#include <list>
#include <functional>
#include <queue>

using std::list;
using std::queue;

class Graph {
private:
    int v;
    list<int> * ob;
    std::priority_queue<int, std::vector<int>, std::greater<int> > q;
    int * indegree;
public:
    Graph(int __v) {
        v = __v;
        ob = new list<int>[v];
        indegree = new int[v];

        for (int i = 0; i < v; ++i) {
            indegree[i] = 0;
        }
    }
    ~Graph() {
        delete [] ob;
        delete [] indegree;
    }
    void insert(int __u, int __v) {
        ob[__u].push_back(__v);
        ++indegree[__v];
    }
    void topoSort() {
        for (int i = 0; i < v; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int flg = false;
        while (!q.empty()) {
            int nown = q.top();
            q.pop();

            if (flg) std::cout << ' ';
            std::cout << nown + 1;
            flg = true;
            for (list<int>::iterator i = ob[nown].begin(); i != ob[nown].end(); ++i) {
                if (--indegree[*i] == 0)
                    q.push(*i);
            }
        }
    }
};

int main() {
    int N, M;
    while (std::cin >> N >> M) {
        Graph g(N);
        for (int i = 0; i < M; ++i) {
            int u, v;
            std::cin >> u >> v;
            g.insert(u - 1, v - 1);
        }
        g.topoSort();
        std::cout << std::endl;
    }
    return 0;
}
