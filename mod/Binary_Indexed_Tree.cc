const int maxn = 1e6;
int bit[maxn], len;

#define lowbit(x) ((x) & (-(x)))

void build(int arr[]) {
    // bit[i] = ask(a[j], {j, i - lowbit(i) + 1, i})
    for (int i = 1; i <= len; ++i) {
        bit[i] = arr[i];
        for (int j = i - 1; j >= i - lowbit(i) + 1; --j) {
            bit[i] += arr[i];
        }
    }
}

void update(int pos, int delta) {
    for (int i = pos; i <= len; i += lowbit(i)) {
        bit[i] += delta;
    }
}

int ask(int pos) {
    int ret = 0;
    for (int i = pos; i >= 1; i -= lowbit(i)) {
        ret += bit[i];
    }
    return ret;
}
