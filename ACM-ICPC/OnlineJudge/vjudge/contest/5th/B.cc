#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
const int maxn = 5e4 + 10;
long long dat[maxn], book[maxn];
bool solved;
long long cnt, sum;
int n;

void dfs(int p) {
    if (solved) return;
    if (sum % n == 0 && sum != 0) {
        solved = true;
        return;
    }
    for (int i = p; i < n; i++) {
        if (book[i]) continue;
        sum += dat[i];
        book[i] = true;
        cnt++;
        dfs(i);
        if (solved) return;
        sum -= dat[i];
        book[i] = false;
        cnt--;
    }
}
int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> dat[i];
    }
    memset(book, false, sizeof(book));
    cnt = 0, sum = 0;
    solved = false;
    dfs(0);
    if (!solved) {
        puts("No Solution");
        return 0;
    }
    std::cout << cnt << std::endl;
    for (int i = 0; i < n; i++) {
        if (book[i])
            std::cout << dat[i] << std::endl;
    }
    return 0;
}
