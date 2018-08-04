#include <iostream>
#include <cstring>
#include <string>

const int maxl = 1e5;

using std::string;

int* getNext(string aim) {
    int len = aim.length();
    int *next = new int[len + 1];
    next[0] = next[1] = 0;

    int j = 0;
    for (int i = 1; i < len; ++i) {
        while (j > 0 && aim[i] != aim[j]) j = next[j];
        if (aim[i] == aim[j]) j++;
        next[i + 1] = j;
    }
    return next;
}

void match(string f, string c, int* next) {
    unsigned mhn = 0; // match number
    for (unsigned i = 0; i < f.size(); ++i) {
        while (mhn > 0 && f[i] != c[mhn]) mhn = next[mhn];
        if (c[mhn] == f[i]) mhn++;
        if (mhn == c.size()) {
            std::cout << "Matched: ";
            std::cout << i - c.size() + 1 << std::endl;
            mhn = next[mhn];
        }
    }
}

