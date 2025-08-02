#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5, M = 2e5;

ll ans;

array<int, N> dsu_link, sz;
array<tuple<int, int, int>, M> edges;

int find(int a) {
	if (dsu_link[a] != a) {
		dsu_link[a] = find(dsu_link[a]); // Path compression
	}
	return dsu_link[a];
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return; // Already in the same set
	if (sz[a] < sz[b]) {
		swap(a, b);
	}
	dsu_link[b] = a; // Union by sz
	sz[a] += sz[b];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		dsu_link[i] = i;
		sz[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b; // Convert to 0-based index
		edges[i] = {c, a, b}; // Store edges as (cost, node1, node2)
	}
	sort(edges.begin(), edges.begin() + m); // Sort edges by cost
	
	for (int i = 0; i < m; i++) {
		auto [c, a, b] = edges[i];
		if (find(a) != find(b)) {
			unite(a, b);
			ans += c; // Add cost to the total
		}
	}
	bool is_connected = true;
	for (int i = 1; i < n; i++) {
		if (find(i) != find(0)) { // Check if all nodes are connected
			is_connected = false;
			break;
		}
	}
	if (is_connected) {
		cout << ans << '\n'; // Output the total cost of the MST
	} else {
		cout << "IMPOSSIBLE\n"; // If not all nodes are connected
	}

	return 0;
}
