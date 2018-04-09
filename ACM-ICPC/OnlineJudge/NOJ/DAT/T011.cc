#include <iostream>
using namespace std;

void fun(int arr[], int len) {
	int tmp = arr[len - 1];
	for (int i = len - 1; i > 0; --i) {
		arr[i] = arr[i - 1];
	}
	arr[0] = tmp;
}

int main() {
	int len, n;
	cin >> len >> n;
	int *arr = new int[len];
	for (int i = 0; i < len; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		fun(arr, len);
	}
	for (int i = 0; i < len; ++i) {
		if (i) cout << ' ';
		cout << arr[i];
	}
	std::cout  << std::endl;
	return 0;
}
