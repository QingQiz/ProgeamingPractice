#include <iostream>

using std::cin;
using std::cout;

int find(int __arr[], int __len, int __aim) {
    int i;
    for (i = 0; i < __len; ++i) {
        if (__arr[i] == __aim) break;
    }
    return i;
}

void remove(int __arr[], int & __len, int __aim) {
    int pos = find(__arr, __len, __aim);
    if (pos == __len) return;
    for (int i = pos; i < __len - 1; ++i) {
        __arr[i] = __arr[i + 1];
    }
    --__len;
}

void input(int __arr[], int __len) {
    for (int i = 0; i < __len; ++i) {
        cin >> __arr[i];
    }
}


int main() {
    int A[101], B[101], C[101];
    int lena, lenb, lenc;
    cin >> lena >> lenb >> lenc;
    input(A, lena);
    input(B, lenb);
    input(C, lenc);
    for (int i = 0; i < lenb; ++i) {
        if (find(C, lenc, B[i]) != lenc) {
            remove(A, lena, B[i]);
        }
    }
    for (int i = 0; i < lena; ++i) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << std::endl;
    return 0;
}
