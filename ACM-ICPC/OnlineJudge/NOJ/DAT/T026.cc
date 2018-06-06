#include <iostream>
#include <string>

using namespace std;

class binTree {
protected:
    int val, maxval, minval;
    binTree *l, *r;
public:
    binTree(int val = 0): val(val), l(NULL), r(NULL) {}

    void build() {
        cin >> val;
        maxval = minval = val;
        if (val == -1) return;

        l = new binTree;
        l -> build();
        r = new binTree;
        r -> build();

        if (l -> val != -1) maxval = max(maxval, r -> maxval);
        if (r -> val != -1) minval = min(minval, l -> minval);
    }
    // traverse and output
    void traverseAll() {
        if (val == -1) return;
        if (l) (*l).traverseAll();
        cout << val << ' ';
        if (r) (*r).traverseAll();
    }
    // merge self to other
    void merge(binTree other) {
        if (val == -1) return;
        if (l) (*l).merge(other);
        if (r) (*r).merge(other);
        other.insert(val);
    }
    void insert(int node) {
        if (val == -1) {
            val = node;
            l = new binTree(-1);
            r = new binTree(-1);
            return;
        }
        if (node > val) {
            if (r) r -> insert(node);
        } else {
            if (l) l -> insert(node);
        }
    }
};

int main() {
    binTree a, b;
    a.build();
    b.build();
    b.merge(a);
    a.traverseAll();
}
