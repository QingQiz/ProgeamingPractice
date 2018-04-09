#include <iostream>
#include <string>

using namespace std;

int findpos(string s, int l, int r) {
	int pos = -1, cmp = 10;
	for (int i = l; i <= r; ++i) {
		if (s[i] - '0' < cmp) {
			cmp = s[i] - '0';
			pos = i;
		}
	}
	return pos;
}

int main() {
	string s; int m;
	while (cin >> s >> m) {
		int ans[1001], top = 0;
		int aimlen = s.length() - m;
		int l = 0, r = s.length() - aimlen;
		while (aimlen) {
			r = s.length() - aimlen;
			ans[top++] = findpos(s, l, r);
			l = ans[top - 1] + 1;
			aimlen--;
		}

		l = 0;
		while (s[ans[l]] == '0') l++;
		if (l == top) cout << '0';
		for (int i = l; i < top; ++i) {
			cout << s[ans[i]];
		}
		cout << endl;
	}
	return 0;
}
