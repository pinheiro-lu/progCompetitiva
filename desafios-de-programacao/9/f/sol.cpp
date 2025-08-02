#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 2e5;

array<vector<pair<int, pair<int, int>>>, N> adj;
array<ll, N> dist;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, t;
	cin >> n >> m >> t;
	while (m--) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		--u; --v;
		adj[u].push_back({v, {x, y}});
		adj[v].push_back({u, {x, y}});
	}

	for (int i = 1; i < n; ++i) {
		dist[i] = LLONG_MAX;
	}
	dist[0] = t;
	priority_queue<pair<ll, int>> pq;
	pq.push({-dist[0], 0});
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		d = -d;
		if (d > dist[u]) continue;
		for (auto [v, p] : adj[u]) {
			if (d % (p.f + p.s) < p.f) {
				if (d < dist[v]) {
					dist[v] = d;
					pq.push({-d, v});
				}
			} else {
				ll nd = d + (p.f + p.s) - (d % (p.f + p.s));
				if (nd < dist[v]) {
					dist[v] = nd;
					pq.push({-nd, v});
				}
			}
		}
	}
	cout << dist[n - 1] << '\n';

	return 0;
}
