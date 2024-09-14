#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<set<int>> adj;

bool search (int u, int v) {
	if (u == v) return true;
	for (int x : adj[u]) {
		if (search(x, v)) return true;
	}
	return false;
}

void solve() {
	cin >> n;
	adj.resize(n);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
	}

	for (int i = 0; i < n; ++i) {
		bool chega = true;
		for (int j = 0; j < n; ++j) {
			if (!search(j, i)) {
				chega = false;
				break;
			}
		}
		if (chega) {
			cout << i + 1 << endl;
			return;
		}
	}

	cout << -1 << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

	while (t--) solve();

	return 0;
}
