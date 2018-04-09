#include <iostream>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	int *q = new int[n];
	int r, &size = n;
	for (int i = 0; i < n - 1; ++i) {
		q[i] = 0;
	}
	q[size - 1] = 1, r = 0;
	while (q[r] < k) {
		int sum = 0;
		for (int i = 0; i < size; ++i) {
			sum += q[i];
		}
		if (sum > k) break;
		q[r] = sum;
		// cout << r << endl;
		// cout << q[1] << ' ' << q[0] << endl;
		r = (r + 1 + size) % size;
	}
	int s;
	for (s = r;s != (r - 1 + size) % size; s = (s + 1 + size) % size) {
		cout << q[s] << ' ';
	}
	cout << q[s] << endl;
}
