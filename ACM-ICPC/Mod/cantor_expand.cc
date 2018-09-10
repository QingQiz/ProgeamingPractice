#include <iostream>


int _10[10] = {
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
};
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800};

inline int npos(int& x, int& n) {
    return x / _10[n - 1] % 10;
}

// x is a permutation of 123456789
// cantor to caculate the position of x in all permutation
int cantor(int x) {
    int res = 0;
    for (int  i = 9; i >= 1; --i) {
        int t = 0;
        for (int j = 9;  j > i; --j) {
            if (npos(x, j) < npos(x, i)) ++t;
        }
        res += fac[i - 1] * (npos(x, i) - 1 - t);
    }
    return res;
}

// rev_cantor to caculate the permutation with the position x
int rev_cantor(int x) {
    int res = 0;
    bool vis[10] = {0};
    for (int i = 9; i >= 1; --i) {
        int tmp = x / fac[i - 1];
        for (int j = 0; j <= tmp; ++j) {
            if (vis[j]) tmp++;
        }
        res = res * 10 + tmp + 1;
        vis[tmp] = 1;
        x %= fac[i - 1];
    }
    return res;
}

