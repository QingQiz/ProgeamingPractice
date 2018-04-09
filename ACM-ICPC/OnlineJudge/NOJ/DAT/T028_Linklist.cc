#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN 1000

class List {
	public:
		char c;
		List *nt, *pv;

		List(char c): c(c), nt(NULL), pv(NULL) {}
};

void insert(List *head, char c) {
	List *ins = new List(c);
	head -> pv -> nt = ins, ins -> pv = head -> pv;
	ins -> nt = head, head -> pv = ins;
}

int main() {
	List *tmp = new List(0);
	List *ans = new List(0);
	tmp -> pv = tmp, tmp -> nt = tmp;
	ans -> pv = ans, ans -> nt = ans;

	int d = MAXN, cnt = 0, a = 1, b = 3, run = 1;

	while (d--) insert(tmp, 0), insert(ans, 0);
	ans -> pv -> c = 2, tmp -> pv -> c = 2;

	while (run && ++cnt < MAXN * 100) {
		d = 0;
		List *pos = tmp -> nt;
		while (pos != tmp) {
			int c = pos -> c * a + d;
			pos -> c = c % 10;
			d = c / 10;
			pos = pos -> nt;
		}

		d = 0;
		pos = tmp -> pv;
		while (pos != tmp) {
			int c = pos -> c + d * 10;
			pos -> c = c / b;
			d = c % b;
			pos = pos -> pv;
		}

		d = 0;
		run = 0;
		List *post = tmp -> nt, *posa = ans -> nt;
		while (post != tmp) {
			int c = posa -> c + post -> c + d;
			posa -> c = c % 10;
			d = c / 10;

			run |= post -> c;
			posa = posa -> nt, post = post -> nt;
		}
		a += 1, b += 2;
	}

	cin >> d, cnt = d + 1;
	List *now = ans -> pv;
	while (cnt--) {
		cout << (int)(now -> c);
		if (cnt == d) putchar('.');
		now = now -> pv;
	}
	putchar('\n');
}
