### LIS

```c++
int dp[maxn];
int LIS(int dt[], int cnt) {
    int len = 1;
    dp[0] = dt[0];

    for (int i = 1; i < cnt; ++i) {
        int l = 0, r = len - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (dt[i] > dp[mid]) l = mid + 1;
            // >= 则为最长不下降子序列
            // <  则为最长下降子序列
            // <= 则为最长不上升子序列
            else r = mid - 1;
        }
        int pos = r + 1;
        dp[pos] = dt[i];
        len = max(len, pos + 1);
    }
    return len;
}
```

### LCS(一组数的两种排列)

```c++
int dt2[maxn], dp[maxn], dt1[maxn];
int too[maxn], dt[maxn];

int LCS() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> dt1[i];
        too[dt1[i]] = i;
    } // 将第一种序列离散化为有序数列
    for (int i = 0; i < n; ++i) cin >> dt2[i];
    // 将第二种序列按照同样的方法离散化
    // 公共部分经过同样的离散化以后得到的序列应是相同的, 同样是递增
    // 因此问题转化为求离散化后的序列的最长上升子序列
    for (int i = 0; i < n; ++i) dt[i] = too[dt2[i]];
    dp[0] = dt[0];
    int len = 1, l, r, mid;
    for (int i = 1; i < n; ++i) {
        l = 0, r = len - 1;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (dt[i] > dp[mid]) l = mid + 1;
            else r = mid - 1;
        }
        int pos = r + 1;
        dp[pos] = dt[i];
        len = max(len, pos + 1);
    }
    return len;
}
```

### 二维凸包

```c++
class Point {
public:
	int x, y;
	friend bool operator < (const Point &a, const Point &b) {
		// 按与x轴夹角由小到大排序, 夹角相同按长度排
		int cmp = a.x * b.y - b.x * a.y;
		if (cmp == 0) return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
		if (cmp > 0) return true;
		return false;
	}
};
bool leftq(Point &a, Point &b, Point &c) {
	// 判断C点是否在ab的左侧
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) >= 0;
}
void getConvexHell(Point arr[], int n, stack<Point> &sta) {
	// arr[]代表点集，n为集合中点的个数，用栈sta存储凸包
	if (!sta.empty()) sta.pop();		// 清空栈
	sort(arr, arr + n);
	Point base = arr[0];				// base 代表纵坐标最小的点
	for (int i = 1; i < n; ++i) {
		if (arr[i].y < base.y) base = arr[i];
	}
	sta.push(base), sta.push(arr[1]);
	for (int i = 2; i < n - 1;) {
		// 连接base和栈顶的那个点，得到直线L, 看当前点是在直线 L 的右边还是左边
		if (leftq(base, sta.top(), arr[i])) {
			// 如果在直线上, 或者在直线的左边, 当前点是凸包上的点, 把它压入栈
			sta.push(arr[i]);
			// 检查当前的点是不是最后一个, 是最后一个的话就结束, 否则判断下一个点
			if (i == n - 1) break;
			else ++i;
		} else {
			// 如果在直线的右边, 则栈顶的那个元素不是凸包上的点, 把栈顶元素出栈
			// 重复判断当前点
			sta.pop();
		}
	}
}
```

### 链式前向星

```c++
class Edge{
public:
    int to; // 指向的节点
    int next; // 下一个该结点的位置
    int w; // 边权
    Edge(): next(-1) {}
};

int head[V]; // 第一个出现某结点的位置
Edge edge[E];

void init() {
    memset(head, -1, sizeof(head));
}

void addedge(int a, int b, int w, int pos) {
    edge[pos].to = b;
    edge[pos].w = w;
    edge[pos].next = head[a];
    head[a] = pos;
}
```

### Dijkstra算法求最短路(优先队列优化)

```c++
typedef std::pair<int, int> pii;
// pair默认按第一个元素排序
// V 代表节点数
// 用链式前向星存图
int d[V], pre[V];
bool solved[V];

void Dijkstra(int v0) {
    for (int i = 0; i < V; ++i) {
        d[i] = INF;
        pre[i] = -1;
    }
    d[v0] = 0, pre[v0] = v0;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
    q.push(std::make_pair(d[v0], v0));

    while (!q.empty()) {
        pii u = q.top();
        q.pop();

        int v = u.second;
        if (solved[v]) continue;
        solved[v] = true;

        for (int nowpos = head[v]; nowpos != -1; nowpos = edge[nowpos].next) {
            int oth = edge[nowpos].to;
            if (d[oth] > d[v] + edge[nowpos].w) {
                d[oth] = d[v] + edge[nowpos].w;
                pre[oth] = v;
                q.push(std::make_pair(d[oth], oth));
            }
        }
    }
}
```

### 拓扑排序

```c++
class Graph {
private:
    int v;                  // 节点总数
    list<int> * ob;         // 邻接表
    queue<int> q;           // 所有入度为0的节点
    int * indegree;         // 所有结点的入度
public:
    Graph(int);             // 构造函数
    ~Graph();               // 析构函数
    void insert(int, int);  // 插入节点
    bool topoSort();        // 拓扑排序
};

Graph::Graph(int __v) {
    v = __v;
    ob = new list<int>[__v];
    indegree = new int[__v];
    for (int i = 0; i < __v; ++i) {
        indegree[i] = 0;
    }
}

Graph::~Graph() {
    delete [] ob;
    delete [] indegree;
}

void Graph::insert(int __u, int __v) {
    ob[__u].push_back(__v);
    ++indegree[__v];
}

bool Graph::topoSort() {
    for (int i = 0; i < v; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int nowv = q.front();
        q.pop();
        cout << nowv + 1 << ' ';
        ++cnt;
        for (list<int>::iterator i = ob[nowv].begin(); i != ob[nowv].end(); ++i) {
            if (--indegree[*i] == 0)
                q.push(*i);
        }
    }
    if (cnt == v) {
        return true;
    }
    return false;
}
```

### 树状数组

```c++
int bit[maxn], len;

#define lowbit(x) ((x) & (-(x)))

void build(int arr[]) { // 初始化
    // bit[i] = ask(a[j], {j, i - lowbit(i) + 1, i})
    for (int i = 1; i <= len; ++i) {
        bit[i] = arr[i];
        for (int j = i - 1; j >= i - lowbit(i) + 1; --j) {
            bit[i] += arr[i];
        }
    }
}

void update(int pos, int delta) { // 节点pos增加delta
    for (int i = pos; i <= len; i += lowbit(i)) {
        bit[i] += delta;
    }
}

int ask(int pos) { // 询问pos位置的前缀和(包含pos)
    int ret = 0;
    for (int i = pos; i >= 1; i -= lowbit(i)) {
        ret += bit[i];
    }
    return ret;
}
```

### 一维ST表

```c++
int stt[100][20];

void init(int l, int r, int *arr) {
	for (int i = l; i <= r; ++i) {
		stt[i][0] = arr[i];
	}
	for (int i = 1; r - l + 1 >= 1 << i; ++i) {
		for (int j = l; r - j + 1 >= 1 << i; ++j) {
			stt[j][i] = max(stt[j][i - 1], stt[j + (1 << (i - 1))][i - 1]);
		}
	}
}

int quary(int l, int r) {
	int len = (int)log2((double)(r - l + 1));
	return max(stt[l][len], stt[r - (1 << len) + 1][len]);
}
```

### 单节点线段树

```c++
int sgt[maxn << 2];

void build(int rt, int l, int r, int arr[]) {
    if (l == r) {
        sgt[rt] = arr[l];
    } else {
        int mid = (l + r) / 2;
        build(rt * 2, l, mid, arr);
        build(rt * 2 + 1, mid + 1, r, arr);
        sgt[rt] = sgt[rt * 2] + sgt[rt * 2 + 1];
    }
}

int query(int rt, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return sgt[rt];
    int mid = (l + r) / 2;
    int ret = 0;
    ret += query(2 * rt, l, mid, ql, qr);
    ret += query(2 * rt + 1, mid + 1, r, ql, qr);
    return ret;
}

void update(int rt, int l, int r, int pos, int add) {
    if (l == r) {
        sgt[rt] += add;
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * rt, l, mid, pos, add);
    } else {
        update(2 * rt + 1, mid + 1, r, pos, add);
    }
    sgt[rt] = sgt[2 * rt] + sgt[2 * rt + 1];
}
```

### 带lazy标记的线段树(区间和)

```c++
typedef long long ll;
#define lson(x) (x << 1)
#define rson(x) (x << 1) | 1

class SGT {
public:
    ll val;
    ll lazy;
    int len;
}sgt[maxn << 2];

void build(int rt, ll arr[], int l, int r) { // 用arr数组建树
    sgt[rt].lazy = 0;
    sgt[rt].len = r - l + 1;
    if (l == r) {
        sgt[rt].val = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(lson(rt), arr, l, mid);
    build(rson(rt), arr, mid + 1, r);
    sgt[rt].val = sgt[lson(rt)].val + sgt[rson(rt)].val;
}

void pushdown(int rt) {
    if (sgt[rt].lazy == 0) return;
    if (sgt[rt].len == 1) return;

    int ls = lson(rt), rs = rson(rt);
    sgt[ls].lazy += sgt[rt].lazy;
    sgt[rs].lazy += sgt[rt].lazy;
    sgt[ls].val += sgt[rt].lazy * sgt[ls].len;
    sgt[rs].val += sgt[rt].lazy * sgt[rs].len;
    sgt[rt].lazy = 0;
}

void update(int rt, int l, int r, int dl, int dr, ll add) {
    pushdown(rt);
    if (dl > r || dr < l) return;
    if (dl <= l && r <= dr) {
        sgt[rt].lazy += add;
        sgt[rt].val += add * sgt[rt].len;
        return;
    }

    int mid = (l + r) / 2;
    update(lson(rt), l, mid, dl, dr, add);
    update(rson(rt), mid + 1, r, dl, dr, add);
    sgt[rt].val = sgt[lson(rt)].val + sgt[rson(rt)].val;
}

ll query(int rt, int l, int r, int ql, int qr) {
    pushdown(rt);
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) {
        return sgt[rt].val;
    }

    int mid = (l + r) / 2;
    ll ret = 0;
    if (l <= mid) {
        ret += query(lson(rt), l, mid, ql, qr);
    }
    if (r > mid) {
        ret += query(rson(rt), mid + 1, r, ql, qr);
    }
    return ret;
}
```

### 字典树(Trie)

```c++
class TrieNode {
public:
    int val;                // 表示以此为前缀的词的个数
    TrieNode * next[26];
    bool exist;             // 表示是否存在以此为结尾的词

    TrieNode(): val(0), exist(false) {
        memset(next, 0, sizeof(next));
    }
};

void node_insert(TrieNode * rt, char *word) {
    // 为字典树插入一个词
    TrieNode * node = rt;
    char * p = word;

    while (*p) {
        int pos = *p++ - 'a';
        if (node -> next[pos] == NULL) {
            node -> next[pos] = new TrieNode;
        }
        node = node -> next[pos];
        ++(node -> val);
    }
    node -> exist = true;
}

int node_search(TrieNode * rt, char * word) {
    // 搜索以word为前缀的词的个数
    TrieNode * node = rt;
    char * p = word;
    while (*p) {
        int pos = *p++ - 'a';
        node = node -> next[pos];
        if (node == NULL) return 0;
    }
    return node -> val;
}

TrieNode * rt = new TrieNode;
```

### exgcd求逆元

```c++
typedef long long ll;
// 首先求解方程 ax + by = gcd(a, b), 得到(x0, y0)
// 然后 x = x0 + b / gcd(a, b) * t, y = y0 - a / gcd(a, b) * t
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    } else {
        ll r = exgcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
} // O(logn)

// find inverse element (a % p)
// 找模p运算下a的逆元
ll mod_inverse(ll a, ll p) {
    ll x, y;
    ll d = exgcd(a, p, x, y);
    if (d == 1) return (x % p + p) % p;
    else return -1;
}
```

### Miller_Rabin 判素数 & 快速幂

```c++
typedef long long ll;
typedef unsigned long long ull;

ull mod_pro(ull a, ull b, ull c) {
    ull ret = 0, tmp = a % c;
    while (b) {
        if (b & 1) {
            if ((ret += tmp) > c) ret -= c;
        }
        if ((tmp <<= 1) > c) tmp -= c;
        b >>= 1;
    }
    return  ret;
} // 计算 (a * b) % c, 这样算是为了防止爆ull

ll QP(ll a, ll b, ll c) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = mod_pro(ret, a, c);
        a = mod_pro(a, a, c);
        b >>= 1;
    }
    return ret;
} // 快速幂

bool primeq(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (!(1 & n)) return false;

    ll m = n - 1, k = 0, t = 3;
    for (; !(1 & m); m >>= 1, ++k);
    while (t--) {
        ll a = QP(rand() % (n - 2) + 2, m, n);
        if (a != 1) {
            int i;
            for (i = 0; i < k && a != n - 1; ++i) {
                a = mod_pro(a, a, n);
            }
            if (i >= k) return false;
        }
    }
    return true;
} // Miller Rabin

// 二次探测定理：对于素数p，0<x<p，x^2 mod p =1 => x=1或p-1。
// 　　由上述定理可推导出：
// 　　如果n是一个奇素数，将n−1表示成m*2^j的形式，m是奇数，a与n是互素的任何整数，
//     那么a^m≡1 mod n或者对某个i(0 ≤i≤ j−1, i∈Z)等式a^(2im)≡−1 mod n成立。

// Miller-Rabin算法的一般步骤:
// 0、先计算出m、j，使得n-1=m*2^j，其中m是正奇数，j是非负整数
// 1、随机取一个a，2<=a
// 2、计算v=a^m mod n
// 3、如果v==1，通过测试，返回
// 4、令i=1
// 5、如果v=n-1，通过测试，返回
// 6、如果i==j，非素数，结束
// 7、v=v^2 mod n，i=i+1
// 8、循环到5
```
