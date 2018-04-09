#include <iostream>
#include <string>

using std::cin;
using std::cout;

char y(char c) {
    switch (c) {
        case '(':
            return ')'; 
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            return '\0';
    }
}
bool j1(char c) {
    if (c == '(' || c == '[' || c == '{') return true;
    return false;
}
bool j2(char c) {
    if (c == ')' || c == ']' || c == '}') return true;
    return false;
}

int main() {
    std::string data;
    char sta[400];
    int top = 0;
    cin >> data;
    bool flg = true;
    for (int i = 0; i < (int)data.length(); i++) {
        if (j1(data[i]) || j2(data[i])) {
            if (j1(data[i])) {
                sta[top++] = data[i];
            } else if (j2(data[i])) {
                if (y(sta[top - 1]) == data[i]) {
                    top--;
                } else {
                    flg = false;
                    break;
                }
            }
        }
    }
    if (flg && top == 0) cout << "yes\n";
    else cout << "no\n";
    return 0;
}
