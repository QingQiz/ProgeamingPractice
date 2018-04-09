#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <climits>
#define max(_, __) \
    (_) > (__) ? (_) : (__);

typedef long long ll;
typedef unsigned long long ull;

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;

class TrieNode {
 public:
    int val;
    TrieNode * next[26];
    bool exist;
};

TrieNode * node_init() {
    TrieNode * p = new TrieNode;
    (*p).val = (*p).exist = 0;
    memset(p -> next, 0, sizeof(p -> next));
    return p;
}

void node_insert(TrieNode * root, char * word) {
    TrieNode * node = root;
    char * p = word;

    while (*p) {
        int pos = *p - 'a';
        if (node -> next[pos] == NULL) {
            node -> next[pos] = node_init();
        }
        node = node -> next[pos];
        p++, ++(node -> val);
    }
    node -> exist = true;
}

int node_search(TrieNode * root, char * word) {
    TrieNode * node = root;
    char * p = word;
    while (*p) {
        int pos = *p++ -'a';
        node = node -> next[pos];
        if (node == NULL)
            return 0;
    }
    return node -> val;
}

int main() {
    TrieNode * root = node_init();
    char word[12], check;
    while (true) {
        check = cin.peek();
        if (check == '\n')
            break;

        scanf("%s", word);
        getchar();
        node_insert(root, word);
    }
    while (~scanf("%s", word)) {
        int ans = node_search(root, word);
        cout << ans << endl;
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/I
// 前缀树,怕ME或者可以用DATrie
// 最简单的前缀树用G++ME, C++ 可过
