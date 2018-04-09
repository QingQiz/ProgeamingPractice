#include <iostream>

int ans[20];

void Solve() {
    int sum;
    for (int k = 1; k < 14; k++) {
        for (int m = k + 1; ; m++) {
            sum = k * 2;
            int flag = 0;
            for (int j = m; ; j += m - 1) {
                j = j % sum ? j % sum : sum;
                if (j <= k) break;
                sum--;
                if(sum == k) {
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                ans[k] = m;
                break;
            }
        }
    }
}

int main(){
    Solve();
    int k;
    while(std::cin >> k && k){
        std::cout << ans[k] << std::endl;
    }
    return 0;
}
