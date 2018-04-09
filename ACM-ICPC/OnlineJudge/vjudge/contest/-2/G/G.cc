#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define fst first
#define snd second

const int M = 60;
const double eps = 1e-9;

int o[20];
bool visited[20];
double G[M][M], dist[M], weight[M], fac[M], b[M], x[M];
map<vector<int>, int> f;

void dfs(int n, vector<int> s, double prob) {
	if (n == 0) {
		sort(s.begin(), s.end());
		if (f.count(s) == 0) {
			int id = f.size();
			f[s] = id;
			//printf("%d:", id);
			//for (auto x : s) printf(" %d", x); printf("\n");
		}
		weight[f[s]] += prob;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		vector<int> v = s;
		v.push_back(i);
		dfs(n - i, v, prob / n);
	}
}

int n;

void solve() {
	memset(o, 0, sizeof(o));
	memset(visited, 0, sizeof(visited));
	memset(G, 0, sizeof(G));
	memset(dist, 0, sizeof(dist));
	memset(weight, 0, sizeof(weight));
	memset(fac, 0, sizeof(fac));
	memset(b, 0, sizeof(b));
	memset(x, 0, sizeof(x));
	f.clear() ;
	
	dfs(n, vector<int>(), 1);
	double sum = 0;
	for (int i = 0; i < f.size(); ++i) {
		//printf("%.5f\n", weight[i]);
		sum += weight[i];
		//printf("sum: %.5f\n", sum);
	}
	
	for (auto it : f) {
		if (it.snd == 0) continue;
		int cnt = 0;
		vector<int> perm;
		for (auto v : it.fst) {
			int old = cnt;
			for (int i = 2; i <= v; ++i) perm.push_back(++cnt);
			perm.push_back(old);
			cnt++;
		}
		for (int a = 0; a < n; ++a) for (int b = a + 1; b < n; ++b) for (int c = b + 1; c < n; ++c) {
			int old[] = {a, b, c}, pos[] = {a, b, c};
			do {
				auto next = perm;
				for (int i = 0; i < 3; ++i) next[pos[i]] = perm[old[i]];
				vector<int> circles;
				for (int i = 0; i < n; ++i) visited[i] = false;
				for (int i = 0; i < n; ++i) {
					if (visited[i]) continue;
					int size = 0;
					for (; !visited[i]; i = next[i]) visited[i] = true, ++size;
					if (size > 0) circles.push_back(size);
				}
				sort(circles.begin(), circles.end());
				auto id = f[circles];
				G[it.snd][id] += 1.0 ;
			} while (next_permutation(pos, pos + 3));
		}
	}
	int m = f.size() - 1;
	for (int i = 1; i <= m; ++i) {
		b[i] = -1.0 * n * (n - 1) * (n - 2) ;
		G[i][i] -= n * (n - 1) * (n - 2) ;
		//for (int j = 1; j <= m; ++j) printf("%.5f ", G[i][j]);
		//printf("\n");
	}
	// Gx = b
	for (int i = 1; i <= m; ++i) {
		int i0 = i;
		for (int j = i ; j <= m ;++j)
			if (fabs(G[j][i]) > fabs(G[i0][i])) i0 = j;
		for (int k = i ; k <= m ;++k) swap(G[i][k], G[i0][k]); swap(b[i], b[i0]);
		for (int j = i+1; j <= m;++j) {
			double tmp = G[j][i] / G[i][i];
			for (int k = i ; k <= m ;++k) {
				G[j][k] -= G[i][k] * tmp;
			}
			b[j] -= b[i] * tmp;
		}
	}
	for (int i = m; i >= 1; --i) {
		x[i] = b[i] / G[i][i];
		for (int j = 1 ; j < i ;++j) {
			b[j] -= G[j][i] * x[i];
		}
	}
	//for (int i = 1 ; i <= m ; i ++ ) printf("%.5f ", x[i]); printf("\n");
	double ans = 0.0 ;
	for (int i = 1; i <= m; i ++) ans += x[i] * weight[i];
	
	char suf[100];
	sprintf(suf, "%.12f", ans);
	for ( int i = 0 , t = 0 ; t < 4 ; i ++ ) {
		if ( suf[i] != '.' ) {
			printf("%c" , suf[i]);
			t ++ ;
		}
	}
	printf("\n");
	//printf("%.12f\n", ans);
}

int main() {
	int Test ; scanf("%d" , &Test);
	for ( int i = 1 ; i <= Test ; i ++ ) {
		scanf("%d", &n) ;
		printf("Case #%d: ", i);
		solve() ;
	}
}
