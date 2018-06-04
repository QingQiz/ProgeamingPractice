#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
    char val;
    Node *l, *r;
    Node(char val = 0): val(val), l(NULL), r(NULL) {}

    bool emptyQ() {
        return !(l || r);
    }
    bool leafQ() {
        if (emptyQ()) return false;
        return l -> emptyQ() && r -> emptyQ();
    }
};

void build(Node *root) {
    char c; cin >> c;
    if (c == '#') return;
    root -> val = c;
    build(root -> l = new Node);
    build(root -> r = new Node);
}

void traverse(Node *root, int &ans) {
    if (root -> leafQ()) { ans++; return; }
    if (root -> l) traverse(root -> l, ans);
    if (root -> r) traverse(root -> r, ans);
}

int main() {
    Node *t = new Node();
    int ans = 0;
    build(t);
    traverse(t, ans);
    cout << ans << endl;
}
