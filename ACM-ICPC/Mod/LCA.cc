// 最近公共祖先(LCA)
// node 是用邻接表存图，que 是询问的列表
// cacd 标记该询问是否已经计算过
// dis 是根节点到其他所有点的距离(根节点任选)
const int maxn = 2e5 + 1;
std::vector<int> node[maxn], que[maxn];
std::map<std::pair<int, int>, bool> cacd;
int dis[maxn];
int n;
long long ans = 0;

void init(int u, int f) { // 初始化距离
  for (int i = 0; i < node[u].size(); ++i) {
    int v = node[u][i];
    if (v == f) continue;
    dis[v] = dis[u] + 1;
    init(v, u);
  }
  return;
}

int f[maxn];
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a != b) f[a] = b;
}
bool vis[maxn]; // vis 标记当前节点是否被访问

void dfs(int u, int las) {
  vis[u] = 1;
  for (auto v : node[u]) {
    if (v == las) continue;
    if (!vis[v]) {
      dfs(v, u);
      merge(v, u);
    }
  }
  // 遍历所有和当前节点相关的询问, 若另外一点没被访问, 则不处理
  for (auto i : que[u]) {
    if (vis[i] && !cacd[std::make_pair(u, i)]) {
      int x = find(i);
      ans += dis[i] + dis[u] - 2 * dis[x] + 1;
      cacd[std::make_pair(u, i)] = cacd[std::make_pair(i, u)] = 1;
    }
  }
}
