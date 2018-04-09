#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> >que;
int main(int argc, char const* argv[])
{
    int n,m;
    while (cin >> n >> m &&(n||m)) {
        int mid;
        for(int i=0;i<n;i++){
            cin >> mid;
            que.push(mid);
        }
        que.push(m);
        cout << que.top();
        que.pop();
        while (!que.empty()) {
            cout << ' ' << que.top();
            que.pop();
        }
        cout << endl;
    }
    return 0;
}
