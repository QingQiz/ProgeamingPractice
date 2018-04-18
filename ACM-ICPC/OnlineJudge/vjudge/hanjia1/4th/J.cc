#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

typedef class TrieNode {
 public:
    int val;
    TrieNode * next[2];
}*trie;

trie node_create() {
    trie p = new TrieNode;
    p -> val = 0;
    p -> next[0] = p->next[1] = NULL;
    return p;
}

void node_insert(trie root, char * aim) {
    trie node = root;
    char *p = aim;

    while (*p) {
        int pos = *p - '0';
        if (node -> next[pos] == NULL) {
            node -> next[pos] = node_create();
        }
        node = node -> next[pos];
        p++, ++(node -> val);
    }
}

int node_search(trie root, char * aim) {
    trie node = root;
    char *p = aim;

    while (*p) {
        int pos = *p++ - '0';
        node = node -> next[pos];
        if (node == NULL)
            return 0;
    }
    return node -> val;
}

void tree_destroy(trie root) {
    trie node = root;
    for (int i = 0; i < 2; i++) {
        if (node -> next[i] != NULL)
            tree_destroy(node -> next[i]);
    }
    delete node;
}

int main() {
    int cnt = 0, n = 0;
    char cases[9][11], check;
    trie root = node_create();

    while (cin >> cases[n]) {
        node_insert(root, cases[n++]);

        getchar();
        check = cin.peek();
        if (check == '9') {
            getchar(), getchar();
            printf("Set %d is ", ++cnt);
            for (int i = 0; i < n; i++) {
                if (node_search(root, cases[i]) > 1) {
                    cout << "not ";
                    break;
                }
            }
            puts("immediately decodable");

            tree_destroy(root);
            root = node_create(), n = 0;
        }
    }
    return 0;
}

// https://vjudge.net/contest/205708#problem/J
// trie树的好题,
// peek的位置开始出了一点问题, 导致少插入一组数据,还好debug出来了
// 要注意树的销毁
