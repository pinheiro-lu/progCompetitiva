#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5 + 5;

array<vector<pair<int, int>>, N> adj;
array<ll, N> dist;
array<bool, N> proc;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c});
    }

    for (int i = 0; i < n; i++) {
        dist[i] = LLONG_MAX;
    }

    dist[0] = 0;
    priority_queue<pair<ll, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int a = q.top().s; q.pop();
        if (proc[a]) continue;
        proc[a] = true;
        for (auto u : adj[a]) {
            int b = u.f, w = u.s;
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}

