#include <iostream>
#include <algorithm>
#include <string>
using std::string;

const int maxn = 1e6;

int rank[maxn], sa[maxn];
int lcp[maxn];
int tmp[maxn];
int n, k;

bool cmp(int i, int j) {
    if (rank[i] != rank[j]) return rank[i] < rank[j];
    int rik = i + k > n ? -1 : rank[i + k];
    int rjk = j + k > n ? -1 : rank[j + k];
    return rik < rjk;
}

void getSA(string s) {
    n = s.length();
    for (int i = 0; i <= n; ++i) {
        sa[i] = i;
        rank[i] = i == n ? -1 : int(s[i]);
    }

    for (k = 1; k <= n; k <<= 1) {
        std::sort(sa, sa + n + 1, cmp);

        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; ++i) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i <= n; ++i) rank[i] = tmp[i];
    }
} // n * log(n) ^ 2

void mkLCP(string s) {
    int n = s.length(), h = 0;
    lcp[0] = 0;

    for (int i = 0; i < n; ++i) {
        int j = sa[rank[i] - 1];

        if (h > 0) --h;
        for ( ; i + h < n && j + h < n; ++h ) {
            if (s[i + h] != s[j + h]) break;
        }
        lcp[rank[i] - 1] = h;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << lcp[i] << std::endl;
    }
}


int main() {
    string s;
    while ( std::cin >> s ) {
        getSA(s);
        mkLCP(s);
        int n = s.length();
        std::cout << "i\t| sa\t| rank\t| suffix\n"
            "---------------------------------------" << std::endl;
        for (int i = 0; i <= n; ++i) {
            std::cout << i << "\t| " << sa[i] << "\t| " << rank[i] << "\t| " + string(s, sa[i]) << std::endl;
            std::cout << "---------------------------------------" << std::endl;
        }
    }
}
