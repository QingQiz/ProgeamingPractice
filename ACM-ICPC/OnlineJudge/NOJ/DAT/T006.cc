#include <iostream>

using namespace std;

class List {
public:
    int d, r;
    List *next, *prev;
    List(int c): d(c), r(0), next(NULL), prev(NULL) {}
};

void insert(List *head, int c) {
    List *p = head;
    List *q = new List(c);
    while (p -> next != head) {
        p = p -> next;
    }
    p -> next = q, q -> next = head;
    q -> prev = p, head -> prev = q;
}

void visit(List *head, int c) {
    List *p = head -> next;
    while (p != head) {
        if (p -> d == c) break;
        p = p -> next;
    }
    if (p != head) {
        p -> r += 1;
        while (p -> prev -> r < p -> r) {
            List *tmp = p -> prev;
            if (tmp == head || p == head) break;
            tmp -> prev -> next = p;
            p -> next -> prev = tmp;
            tmp -> next = p -> next;
            p -> prev = tmp -> prev;
            p -> next = tmp;
            tmp -> prev = p;
        }
    }
}

int main() {
    int m, n, i;
    cin >> m >> n;
    List *head = new List(0);
    head -> next = head, head -> prev = head;
    for (i = 0; i < m; ++i) {
        char c; cin >> c;
        insert(head, c);
    }
    for (i = 0; i < n; ++i) {
        char c; cin >> c;
        visit(head, c);
    }
    List *now = head -> next;
    while (now != head) {
        cout << (char)(now -> d) << ' ';
        now = now -> next;
    }
    return 0;
}
