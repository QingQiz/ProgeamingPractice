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

    for (int i = 0; i < len; i++) {
        p -> next = new List;
        p = p -> next;
        cin >> (p -> val);
    }
    return ret;
}

List *merge(List *l, List *r) {
    l = l -> next, r = r -> next;
    List *ret = new List;
    List *p;

    while (l && r) {
        p = new List;
        p -> next = ret -> next;
        ret -> next = p;

        if (l -> val > r -> val) {
            p -> val = r -> val;
            r = r -> next;
        } else {
            p -> val = l -> val;
            l = l -> next;
        }
    }
    while (l) {
        p = new List;
        p -> next = ret -> next;
        ret -> next = p;

        p -> val = l -> val;
        l = l -> next;
    }
    while (r) {
        p = new List;
        p -> next = ret -> next;
        ret -> next = p;
        
        p -> val = r -> val;
        r = r -> next;
    }
    return ret;
}


int main() {
    int lena, lenb;
    cin >> lena >> lenb;;
    List *a, *b, *c;
    a = create(lena);
    b = create(lenb);
    c = merge(a, b);
    c = c -> next;
    while (c) {
        cout << c -> val << ' ';
        c = c -> next;
    }
    return 0;
}
