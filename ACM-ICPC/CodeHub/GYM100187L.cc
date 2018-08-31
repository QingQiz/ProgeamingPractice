#include <iostream>
#include <string>

using std::string;

int main() {
    string s;
    std::cin >> s;
    int len = s.length();
    for (int i = 0; ; ++i) {
        int j = len - 1 - i;
        if (j <= i) break;
        if (s[i] != s[j])
            s[j] = s[i];
    }
    std::cout << s << std::endl;
}
