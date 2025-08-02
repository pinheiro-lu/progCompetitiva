#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5;
struct State {
	ll dist;
	bool is_train;
	bool operator<(const State& other) const {
		if (dist != other.dist) return dist < other.dist;
		return is_train < other.is_train;
	}
};
array<vector<pair<int, State>>, N> adj;
array<State, N> dist;
priority_queue<pair<State, int>> pq;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back({v, {w, false}});
		adj[v].push_back({u, {w, false}});
	}
	dist.fill({LLONG_MAX, true});
	int ans = k;
	while (k--) {
		int s, y;
		cin >> s >> y;
		--s;
		adj[0].push_back({s, {y, true}});
	}
	pq.push({{0, false}, 0}); // {distance, node, train?}
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		d.dist = -d.dist; // Convert back to positive distance
		if (dist[u] < d) continue; // Skip if we already found a better path
		//cerr << "Processing node " << u + 1 << " with distance " << d << '\n';
		dist[u] = d; // Update the distance for node u
		for (auto [v, w] : adj[u]) {
			State coming = {d.dist + w.dist, w.is_train};
			if (coming < dist[v]) {
				pq.push({{-coming.dist, coming.is_train}, v}); // Push negative distance for max-heap behavior
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		ans -= dist[i].is_train; // Count the number of train rides
	}

	cout << ans << '\n';

	return 0;
}

