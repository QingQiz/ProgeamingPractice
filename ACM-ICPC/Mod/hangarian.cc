bool dfs(int u) {
    for (unsigned i = 0; i < e[u].size(); ++i) {
        int v = e[u][i];
        if (!vis[v]) {
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[u] = v, match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hangarian() {
    int answer = 0;
    memset(match, -1, sizeof match);
    for (int i = 1; i <= n; ++i) {
        if (match[i] == -1) {
            memset(vis, 0, sizeof vis);
            if (dfs(i)) answer++;
        }
    }
    return answer;
}
