#include <iostream>

using std::cin;
using std::cout;

#define OUTPUT

template <typename T>
class List {
public:
    T value;
    List * next;

    List(): next(NULL){}
    ~List() {
        List * p = this -> next, *q;
        this -> next = NULL;
        while (p != NULL) {
            q = p -> next;
            delete p;
            p = q;
        }
    }
    void insert(T __aim) {
        List * data = new List;
        data -> value = __aim;

        List * p = this -> next, *q = this;
        while (p != NULL) {
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

int main() {
    int arr[1000], len;
    cin >> len;
    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < len; ++i) {
        if (i < len - 1 - i) {
            arr[i] ^= arr[len - 1 - i];
            arr[len - 1 - i] ^= arr[i];
            arr[i] ^= arr[len - 1 - i];
        } else {
            break;
        }
    }
    List<int> ls;
    for (int i = 0; i < len; i++) {
        ls.insert(arr[i]);
    }
    for (int i = 0; i < len; ++i) {
        if (i) cout << ' ';
        cout << arr[i];
    }
    cout << std::endl;
    ls.display();
    cout << std::endl;
    return 0;
}
