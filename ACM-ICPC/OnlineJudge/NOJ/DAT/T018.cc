#include <iostream>
#include <string>

using namespace std;

class binTree {
protected:
    char node;
    binTree *l, *r;
public:
    binTree(): node(0), l(NULL), r(NULL) {}

    void traverse() {
        if (l) l -> traverse();
        if (r) r -> traverse();
        cout << node;
    }

    void rebuild(string p, string q) {
        if (p == "" || q == "") return;
        rebuild(p, 0, p.size() - 1, q, 0, q.size() - 1);
    }
    void rebuild(string p, int pstart, int pend, string q, int qstart, int qend) {
        node = p.at(pstart);
        if (pstart == pend || qstart == qend) return;
        int root;
        for (root = qstart; root <= qend; ++root) {
            if (p.at(pstart) == q.at(root)) break;
        }
        int leftlength = root - qstart;
        int rightlength = qend - root;
        if (leftlength > 0) {
            l = new binTree();
            l -> rebuild(p, pstart + 1, pstart + leftlength, q, qstart, root - 1);
        }
        if (rightlength > 0) {
            r = new binTree();
            r -> rebuild(p, pstart + leftlength + 1, pend, q, root + 1, qend);
        }
    }
};

int main() {
    string p, q;
    cin >> p >> q;
    binTree root;
    root.rebuild(p, q);
    root.traverse();
}
