#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int now = 0;
    int ans = 0;
    for (unsigned i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == '(') now++;
        else if (c == ')') now--;
        ans = max(ans, now);
    }
    cout << ans << endl;
    now = ans = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        char c = s[i];
        if (c == '(') now--;
        else if (c == ')') now++;
        ans = max(ans, now);
    }
    cout << ans << endl;
}
