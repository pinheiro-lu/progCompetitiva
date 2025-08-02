#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef vector<int> vi;

#define f first
#define s second

int n;
const int N = 2e5+1;

array<int, N> dang, ans, par;
// dp[i] saves the best with i positive in the alternaing sum
array<vi, N> adj;

void solve (int idx) {
	ans[idx] = max(dang[idx], dang[idx] - dang[par[idx]] + ans[par[par[idx]]]);
}

void dfs(int idx, int my_par) {
	par[idx] = my_par;
	solve(idx);
	for (auto &v : adj[idx]) {
		if (v == my_par) continue;
		dfs(v, idx);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt; cin >> tt;

	while (tt--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			dang[i] = x;
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(1, 0);

		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}


	return 0;
}
