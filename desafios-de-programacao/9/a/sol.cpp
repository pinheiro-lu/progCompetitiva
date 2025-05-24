#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5;

array<vi, N> adj;
array<int, N> dist;
array<bool, N> vis;
array<int, N> pai;

void print_path(int node) {
    if (node == -1) return;
    print_path(pai[node]);
    cout << node + 1 << " ";
}

signed main() {
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

    queue<int> q;
    vis[0] = true;
    dist[0] = 0;
    pai[0] = -1;
    q.push(0);

    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (vis[u]) continue;
            vis[u] = true;
            dist[u] = dist[s] + 1;
            pai[u] = s;
            q.push(u);
        }
    }

    if (!vis[n - 1]) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n - 1] + 1 << '\n';
        print_path(n - 1);
        cout << '\n';
    }

    return 0;
}

