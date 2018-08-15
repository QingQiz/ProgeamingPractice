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
};
void insert(char* s, int identity, trie* t) {
    trie* now = t;
    char* p = s;
    while (*p) {
        int pos = *p++ - 'a';
        if (now -> next[pos] == NULL)
            now -> next[pos] = new trie;
        now = now -> next[pos];
    }
    now -> id = identity;
    now -> cnt++;
}
void mkfailptr(trie* t) {
    std::queue<trie*> q;
    q.push(t);
    while (!q.empty()) {
        trie* now = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
            if (now -> next[i] == NULL) continue;
            if (now != t) {
                trie* p = now -> fail;
                while (p && p -> next[i] == NULL) p = p -> fail;
                now -> next[i] -> fail = p ? p -> next[i] : t;
            } else now -> next[i] -> fail = t;
            q.push(now -> next[i]);
        }
    }
}
int query(char* s, trie* t) {
    int len = strlen(s);
    int ret = 0;
    trie* p = t;
    for (int i = 0; i < len; ++i) {
        int pos = s[i] - 'a';
        while (p -> next[pos] == NULL && p != t) p = p -> fail;
        if (p -> next[pos] == NULL) continue;
        p = p -> next[pos];
        trie* findall = p;
        while (findall != t) {
            if (findall -> cnt) ret += findall -> cnt;
            findall = findall -> fail;
        }
    }
    return ret;
}
void destory(trie* t) {
    for (int i = 0; i < 26; ++i) {
        if (t -> next[i] != NULL) destory(t -> next[i]);
    }
    delete t;
}
