#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

bool j(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

char stao[100];
string stan[100];
int tn = 0, to = 0;
int rank[1000];

int main() {
    rank[(int)'+'] = rank[(int)'-'] = 1, rank[(int)'*'] = rank[(int)'/'] = 2;

    string s;
    cin >> s;

    for (int i = 0; i < int(s.length()); i++) {
        if (s[i] == '(') {
            stao[to++] = '(';
        } else if (s[i] == ')') {
            while (stao[to - 1] != '(') {
                stan[tn - 2] += stan[tn - 1] + stao[to - 1];
                tn -= 1, to -= 1;
            }
            to -= 1;
        } else if (j(s[i])) {
            while (rank[(int)stao[to - 1]] >= rank[(int)s[i]]) {
                stan[tn - 2] += stan[tn - 1] + stao[to - 1];
                tn -= 1, to -= 1;
            }
            stao[to++] = s[i];
        } else {
            stan[tn++] = s[i];
        }
    }
    while (to) {
        stan[tn - 2] += stan[tn - 1] + stao[to - 1];
        tn -= 1, to -= 1;
    }
    cout << stan[0] << std::endl;
    return 0;

}
