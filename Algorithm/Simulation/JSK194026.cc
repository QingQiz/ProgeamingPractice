// https://www.jisuanke.com/contest/2290/194026
#include <iostream>

const int maxn = 100000+5;
int ________[100];
int _[maxn];
int a[maxn];
int n;
void pre_process() {
	_[1] = a[1];
	_[0] = _[-1] = _[-2] =_[-3] = 0;
	_[2] = a[2];
	_[3] = a[3];
	_[4] = a[4];
	for (int i = 5; i <= n; ++i) {
		_[i] = (_[i - 4] ^ a[i]);
	}
}

int cacu(int l, int r) {
	int len = (r - l + 1);
	int x = (len + 1) / 2;
	int y = (len) / 2;
	int a, b;
	if (x % 2 == 0) {
		a = 0;
	} else {
		a = _[l + (r - l) / 4 * 4] ^ _[l - 4];
	}
	if (y % 2 == 0) {
		b = 0;
	} else {
		b = _[l + 1 + (r - l) / 4 * 4] ^ _[l + 1 - 4];
	}
	return a ^ b;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		pre_process();
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; ++i) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", cacu(l, r));
		}
	}
}
