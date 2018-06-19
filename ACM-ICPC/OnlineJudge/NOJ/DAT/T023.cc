#include <iostream>

using namespace std;

inline int hash(int k) { return (3 * k % 11); }

class HashT {
protected:
    int table[11];
    int sizet;
public:
    HashT();
    int hash(int k) { return 3 * k % 11; }
    void build(int[], int);
    int quary(int q);
};

HashT::HashT():sizet(11) {
    for (int i = 0; i < 10; ++i) {
        table[i] = -1;
    }
}

void HashT::build(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        int pos = hash(arr[i]);
        while (table[pos] != -1) pos++;
        table[pos] = arr[i];
    }
}

int HashT::quary(int q) {
    int pos = hash(q);
    int ret = 1;
    while (pos < sizet && table[pos] != -1) {
        if (table[pos] == q) return ret;
        pos++, ret++;
    }
    return -1;
}

int main() {
    HashT h;
    int arr[] = {22, 41, 53, 46, 30, 13, 01, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    h.build(arr, size);
    int ans = 0;
    for (int i = 0; i < size; ++i) {
        ans += h.quary(arr[i]);
    }
    cout << ans / size << endl;
}
