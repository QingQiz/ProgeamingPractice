#include <iostream>
#include <cstring>

using namespace std;

class TrieNode {
public:
    int val;                // 表示以此为前缀的词的个数
    TrieNode * next[26];
    bool exist;             // 表示是否存在以此为结尾的词

    TrieNode(): val(0), exist(false) {
        memset(next, 0, sizeof(next));
    }
};

void node_insert(TrieNode * rt, char *word) {
    // 为字典树插入一个词
    TrieNode * node = rt;
    char * p = word;

    while (*p) {
        int pos = *p++ - 'a';
        if (node -> next[pos] == NULL) {
            node -> next[pos] = new TrieNode;
        }
        node = node -> next[pos];
        ++(node -> val);
    }
    node -> exist = true;
}

int node_search(TrieNode * rt, char * word) {
    // 搜索以word为前缀的词的个数
    TrieNode * node = rt;
    char * p = word;
    while (*p) {
        int pos = *p++ - 'a';
        node = node -> next[pos];
        if (node == NULL) return 0;
    }
    return node -> val;
}

TrieNode * rt = new TrieNode;
