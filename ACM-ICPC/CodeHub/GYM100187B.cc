#include <iostream>
#include <string>

using namespace std;

int b[26];
int main() {
    string s;
    std::cin >> s;
    for (unsigned i = 0; i < s.length(); ++i) {
        b[s[i] - 'a']++;
    }
    double res  = 0;
    for (int i = 0; i < 26; ++i) {
        long double m = (long double)b[i] / s.length();
        m *= m;
        res += m;
    }
    printf("%.15lf\n", res * s.length());
}
