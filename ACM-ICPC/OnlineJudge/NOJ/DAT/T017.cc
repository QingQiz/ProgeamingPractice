#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct Node {
    char val;
    Node *l ,*r;
    Node(): val(0), l(NULL), r(NULL) {}
}*t;

void build(Node *rt) {
    char c; cin >> c;
    if (c == '#') return;
    rt -> val = c;
    build(rt -> l = new Node);
    build(rt -> r = new Node);
}

void traverse(Node *rt) {
    if (!rt) return;
    if (rt -> val == 0) return;
    traverse(rt -> l);
    cout << rt -> val;
    traverse(rt -> r);
}

int main() {
    t = new Node;
    build(t);
    traverse(t);
    cout << endl;
}
