#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

const int maxn = 2e5 + 1;
std::vector<int> node[maxn], que[maxn];
std::map<std::pair<int, int>, bool> cacd;
int dis[maxn];
int n;
long long ans = 0;

void init(int u, int f) {
  for (int i = 0; i < node[u].size(); ++i) {
    int v = node[u][i];
    if (v == f) continue;
    dis[v] = dis[u] + 1;
    init(v, u);
  }
  return;
}

int f[maxn];
bool vis[maxn];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a != b) f[a] = b;
}

void tarjan(int u, int las) {
  vis[u] = 1;
  for (auto v : node[u]) {
    if (v == las) continue;
    if (!vis[v]) {
      tarjan(v, u);
      merge(v, u);
    }
    // vis[v] = 1;
  }
  for (auto i : que[u]) {
    if (vis[i] && !cacd[std::make_pair(u, i)]) {
      int x = find(i);
      ans += dis[i] + dis[u] - 2 * dis[x] + 1;
      cacd[std::make_pair(u, i)] = cacd[std::make_pair(i, u)] = 1;
      //std::cout << "\t" << u << ' ' << i << ' ';
      //std::cout << dis[i] + dis[u] - 2 * dis[x] + 1 << std::endl;
    }
  }
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    node[a].push_back(b);
    node[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i * 2; j <= n; j += i) {
      que[i].push_back(j);
      que[j].push_back(i);
    }
  }
  for (int i = 0; i <= n; ++i) f[i] = i;
  dis[1] = 1;
  init(1, 0);
  tarjan(1, 0);
  std::cout << ans << std::endl;
  return 0;
}
