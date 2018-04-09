#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using std::vector;
using std::cin;
using std::cout;

const int maxn = 500000;

int primenum;
bool primeq[maxn];
vector<int> primelist;

void get_prime() {
    primeq[0] = primeq[1] = true;

    for (int i = 2; i < maxn; i++) {
        if (primeq[i])
            continue;
        primelist.push_back(i);
        if (i >= maxn / i)
            continue;
        for (int j = i * i; j < maxn; j += i) {
            primeq[j] = true;
        }
    }
    primenum = primelist.size();
}

int get_sum(int n) {
    int nown = n, sum = 1;
    for (int i = 0; i < primenum; i++) {
        if (nown % primelist[i] == 0) {
            int num = 0, pro = 1;
            while (nown % primelist[i] == 0) {
                nown /= primelist[i];
                num += pro;
                pro *= primelist[i];
            }
            num += pro;
            sum *= num;
        }
        if (nown == 1) {
            break;
        }
    }
    if (nown != 1) {
        sum *= 2;
    }
    return sum - n;
}

int main() {
    get_prime();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << get_sum(n) << '\n';
    }
    return 0;
}
