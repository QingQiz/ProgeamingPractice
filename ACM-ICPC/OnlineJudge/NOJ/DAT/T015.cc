#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
    char val;
    Node *l;
    Node *r;

    Node(int val = 0, Node *l = NULL, Node *r = NULL): val(val), l(l), r(r) {}
}*t;

void delChar() {
    char c;
    do {
        c = getchar();
    } while (c == ' ');
}

void build(Node *root) {
    cin >> (root -> val);
    if (root -> val == '#') return;
    char c = cin.peek();
    if (c == ')') return;
    delChar();
    build(root -> l = new Node());
    delChar();
    build(root -> r = new Node());
    delChar();
}

void traverse(Node *root) {
    if (root == NULL) return;
    cout << root -> val;
    traverse(root -> l);
    traverse(root -> r);
}

int main() {
    t = new Node();
    build(t);
    traverse(t);
    cout << endl;
}
