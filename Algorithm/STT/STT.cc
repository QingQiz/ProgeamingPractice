#include <iostream>
#include <cmath>

// st table
void init(int l, int r, int *arr, int stt[][20]) {
	for (int i = l; i <= r; ++i) {
		stt[i][0] = arr[i];
	}

	for (int i = 1; r - l + 1 >= 1 << i; ++i) {
		for (int j = l; r - j + 1 >= 1 << i; ++j) {
			stt[j][i] = std::max(stt[j][i - 1], stt[j + (1 << (i - 1))][i - 1]);
		}
	}
}

int quary(int l, int r, int stt[][20]) {
	int len = (int)log2((double)(r - l + 1));
	return std::max(stt[l][len], stt[r - (1 << len) + 1][len]);
}
// end st table


// test
int main() {
	// std::cout << log2(1e6) << std::endl;
	int stt[100][20];
	int arr[100], n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i + 1];
	}
	init(1, n, arr, stt);
	int m; std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r;
		std::cin >> l >> r;
		std::cout << quary(l, r, stt) << std::endl;
	}
	return 0;
}
// end test
