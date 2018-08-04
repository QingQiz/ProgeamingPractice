#include <iostream>
#include <queue>
#include <cstring>

struct trie {
    trie* next[26];
    trie* fail;
    int id;
    int cnt;
    trie(): fail(NULL), id(-1), cnt(0) {
        memset(next, 0, sizeof next);
    }
    void insert(char* s, int identity) {
        trie* now = this;
        char* p = s;
        while (*p) {
            int pos = *p++ - 'A';
            if (now -> next[pos] == NULL)
                now -> next[pos] = new trie;
            now = now -> next[pos];
        }
        now -> id = identity;
        now -> cnt++;
    }
    void mkfailptr() {
        std::queue<trie*> q;
        q.push(this);
        while (!q.empty()) {
            trie* now = q.front();
            q.pop();
            for (int i = 0; i < 26; ++i) {
                if (now -> next[i] == NULL) continue;
                if (now != this) {
                    trie* p = now -> fail;
                    while (p && p -> next[i] == NULL) p = p -> fail;
                    now -> next[i] -> fail = p ? p -> next[i] : this;
                } else now -> next[i] -> fail = this;
                q.push(now -> next[i]);
            }
        }
    }
    int query(char* s) {
        int len = strlen(s);
        int ret = 0;
        trie* p = this;
        for (int i = 0; i < len; ++i) {
            if (s[i] < 'A' || s[i] > 'Z') continue;
            int pos = s[i] - 'A';
            while (p -> next[pos] == NULL && p != this) p = p -> fail;
            if (p -> next[pos] == NULL) continue;
            p = p -> next[pos];
            trie* findall = p;
            while (findall != this) {
                if (findall -> id != -1) ret++;
                findall = findall -> fail;
            }
        }
        return ret;
    }
};
