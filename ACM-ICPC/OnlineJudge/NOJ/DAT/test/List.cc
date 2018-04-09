#ifndef NULL
#define NULL 0x0
#endif

template <typename T>
bool __cmp(T __l, T __r) {
    return __l < __r;
}

template <typename T>
class List {
public:
    T value;
    List * next;
    bool (*cmpfunc)(T, T);

    List(): next(NULL), cmpfunc(__cmp) {}
    List(bool (*Cfunc)(T, T)): next(NULL) {
        cmpfunc = Cfunc;
    }
#ifdef DESTORY
    ~List() {
        List * p = this -> next, *q;
        this -> next = NULL;
        while (p != NULL) {
            q = p -> next;
            delete p;
            p = q;
        }
    }
#endif
    void insert(T __aim) {
        List * data = new List;
        data -> value = __aim;

        List * p = this -> next, *q = this;
        while (p != NULL && !cmpfunc(__aim, p -> value)) {
            p = p -> next;
            q = q -> next;
        }
        if (p == NULL) {
            q -> next = data;
        } else {
            data -> next = q -> next;
            q -> next = data;
        }
    }
    void remove(T __aim) {
        List *p, *q;
        p = this -> next, q = this;
        while (p != NULL) {
            if (p -> value == __aim) {
                q -> next = p -> next;
                delete p;
            }
            p = p -> next;
            q = q -> next;
        }
    }
    bool find(T __aim) {
        List *p = this -> next;
        while (p != NULL) {
            if (p -> value == __aim) {
                return true;
            }
            p = p -> next;
        }
        return false;
    }
#ifdef OUTPUT
    void display() {
        List * p = this -> next;
        if (p != NULL) {
            cout << (p -> value);
            p = p -> next;
        }
        while (p != NULL) {
            cout << ' ' << (p -> value);
            p = p -> next;
        }
    }
#endif
};
