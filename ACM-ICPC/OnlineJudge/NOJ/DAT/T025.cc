#include <iostream>
#include <string>

using namespace std;

class binTree {
protected:
    int val, maxval, minval;
    binTree *l, *r;
public:
    binTree(int val = 0): val(val), l(NULL), r(NULL) {}
    void maketmp(int a) { val = a, l = new binTree(-1), r = new binTree(-1);}
    int minimun() { return minval; }
    int maximum() { return maxval; }

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
    bool leaf() {
        if (l -> val == -1 && r -> val == -1) return true;
        return false;
    }
    void traverseForRange(int a, int b) {
        if (val == -1) return;
        if (leaf()) {
            if (val < b && val > a) cout << val << ' ';
            return;
        }
        if (val <= a) {
            if (l) r -> traverseForRange(a, b);
        } else if (val >= b) {
            if (l) l -> traverseForRange(a, b); 
        } else {
            if (l) l -> traverseForRange(a, b);
            cout << val << ' ';
            if (r) r -> traverseForRange(a, b);
        }
    }
    void traverseAll() {
        if (val == -1) return;
        if (l) (*l).traverseAll();
        cout << val << ' ';
        if (r) (*r).traverseAll();
    }
    void insert(binTree& node) {
        if (val == -1) {
            val = node.val;
            l = node.l;
            r = node.r;
            return;
        }
        if (node.val > val) {
            if (r) r -> insert(node);
            else r = &node;
        } else {
            if (l) l -> insert(node);
            else l = &node;
        }
    }
};

int main() {
    binTree t, tmp;
    int a, b;

    t.build();

    cin >> a >> b;
    t.traverseForRange(a, b);
    cout << endl;

    cin >> a;
    tmp.maketmp(a);
    t.insert(tmp);
    t.traverseAll();
    cout << endl;

    cin >> b;
    int c = min(a, b), d = max(a, b);
    t.traverseForRange(t.minimun() - 1, c);
    t.traverseForRange(c, d);
    t.traverseForRange(d, t.maximum() + 1);
    cout << endl;
}

