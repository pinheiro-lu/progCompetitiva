#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 3e5+7;
const int LG = 20;

vector<vector<int>> adj;
vector<ll> a;
array<array<ll, LG>, N> dp;

void dfs(int u, int p) {
	for (int i = 0; i < LG; ++i) {
		dp.at(u).at(i) = (i+1) * a[u];
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		for (int i = 0; i < LG; ++i) {
			ll mn = LLONG_MAX;
			for (int j = 0; j < LG; ++j) {
				if (i == j) continue;
				mn = min(mn, dp.at(v).at(j));
			}
			dp.at(u).at(i) += mn;
		}
	}
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		adj.assign(n, vector<int>());
		a.assign(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(0, -1);

		ll ans = LLONG_MAX;
		for (int i = 0; i < LG; ++i) {
			ans = min(ans, dp.at(0).at(i));
		}
		cout << ans << '\n';
	}

	return 0;
}
