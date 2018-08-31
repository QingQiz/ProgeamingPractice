#include <iostream>

int main() {
    int n, k; std::cin >> n >> k;
    if (n == 1 && k == 1) {
        puts("0");
        return 0;
    }
    if (k == n) {
        puts("-1");
        return 0;
    }
    if (k == 1) {
        std::cout << n - 1 << std::endl;
        return 0;
    }
    int x = n / k;
    int res = n % k;
    if (res > 1) x++;
    std::cout << x << std::endl;
}
