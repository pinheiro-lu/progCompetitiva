#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 2e5;

array<int, N> a;
array<vi, N> adj;

int dfs(int v) {
	int mn = INT_MAX;
	for (int u : adj[v]) {
		mn = min(mn, dfs(u));
	}

	//cerr << v << ' ' << a[v] << ' ' << mn << '\n';
	if (mn == INT_MAX) {
		return a[v];
	}
	if (mn < a[v]) return mn;
	return (mn + a[v]) / 2;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		adj.fill(vi());
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i < n; ++i) {
			int x; cin >> x;
			--x;
			adj[x].push_back(i);
		}

		int ans = a[0];
		int mn = INT_MAX;

		for (int u : adj[0]) {
			//cerr << u << ' ' << dfs(u) << '\n';
			mn = min(mn, dfs(u));
		}

		cout << ans + mn << '\n';


	}



	return 0;
}
