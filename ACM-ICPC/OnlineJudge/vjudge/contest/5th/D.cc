#include <iomanip>
#include <iostream>
#include <cmath>

int main() {
    const char str[2][10] = {
        "Alice", "Bob"
    };
    int n;
    while (std::cin >> n && n) {
        if (n == 1 || n == 2)
            puts(str[0]);
        else {
            puts(str[1]);
        }
    }
    return 0;
}
