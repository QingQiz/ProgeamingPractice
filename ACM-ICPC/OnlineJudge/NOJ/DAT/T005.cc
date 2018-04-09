#include <iostream>

using std::cin;
using std::cout;

class List {
public:
    int val;
    List *next;

    List(): val(0), next(NULL) {}
};

List *create(int len) {
    List *ret, *p;
    p = ret = new List;
    for (int i = 0; i < len; ++i) {
        p -> next = new List;
        p = p -> next;
        cin >> p -> val;
    }
    return ret;
}

bool find(List *ls, int aim) {
    ls = ls -> next;
    while (ls) {
        if (ls -> val == aim)
            break;
        ls = ls -> next;
    }
    if (ls) return true;
    return false;
}

void remove(List *ls, int aim) {
    List *p = ls, *q = p -> next;
    while (q) {
        if (q -> val == aim) {
            break;
        }
        p = q;
        q = q -> next;
    }
    if (q) {
        p -> next = q -> next;
        delete q;
    }
}
