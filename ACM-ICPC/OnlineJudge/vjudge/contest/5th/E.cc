#include <iomanip>
#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        double l, d;
        std::cin >> l >> d;
        if (d >= l) {
            puts("0.000000");
        } else {
            l /= d;
            double ans = log(l);
            ans++;
            std::cout.setf(std::ios::fixed);
            std::cout << std::setprecision(6) << ans << std::endl;
        }
    }
    return 0;
}
