#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<long long> sum(n + 1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            sum[u] += a[v];
        }
    }
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int x;
            int y;
            cin >> x >> y;
            int diff = y - a[x];
            a[x] = y;
            for (int v : g[x]) {
                sum[v] += diff;
            }
        } 
        else {
            int x;
            cin >> x;
            cout << a[x] + sum[x] << "\n";
        }
    }
    return 0;
}