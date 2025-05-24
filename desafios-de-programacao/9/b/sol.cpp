#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

array<vector<int>, N> adj;
array<int, N> col;
array<bool, N> vis;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ok = true;

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;

        queue<int> q;
        q.push(i);
        col[i] = 1;
        vis[i] = true;

        while (!q.empty()) {
            int s = q.front(); q.pop();
            for (int u : adj[s]) {
                if (!vis[u]) {
                    col[u] = col[s] ^ 3;  // alterna entre 1 e 2
                    vis[u] = true;
                    q.push(u);
                } else if (col[u] == col[s]) {
                    ok = false;
                }
            }
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << col[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

