#include <iostream>

using std::cin;

class List {
public:
    int val;
    List * next;
    List * prev;

    List(): next(this), prev(this) {}
};



void insert(List * L, int val) {
    List *q = new List;
    L -> prev -> next = q;
    q -> next = L;
    q -> prev = L -> prev;
    L -> prev = q;
    q -> val = val;
}


int main() {

    List *head = new List;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        insert(head, tmp);
    }

    List *ans = new List;
    List *p = head -> next, *q = head -> prev;
    while (1) {
        if (p != q) {
            insert(ans, p -> val);
            insert(ans, q -> val);
        } else {
            insert(ans, p -> val);
            break;
        }
        p = p -> next;
        if (p == q) break;
        q = q -> prev;
    }
    p = ans -> next;
    while (p != ans) {
        std::cout << (p -> val) << ' ';
        p = p -> next;
    }
    return 0;
}
