#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 2e5, LOG = 19;

array<int, N> par, depth, ans, cnt;
vector<pair<int, int>> dep;
array<array<int, LOG>, N> anc;
array<vi, N> adj;

int n, q;

void dfs(int v, int p) {
	par[v] = p;
	for (int u : adj[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + 1;
		dep.push_back({-depth[u], u});
		dfs(u, v);
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;

	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, -1);
	dep.push_back({0, 0});

	for (int i = 0; i < n; ++i) {
		anc[i][0] = par[i];
	}

	for (int j = 1; j < LOG; ++j) {
		for (int i = 0; i < n; ++i) {
			if (anc[i][j - 1] == -1) {
				anc[i][j] = -1;
			} else {
				anc[i][j] = anc[anc[i][j - 1]][j - 1];
			}
		}
	}

	for (int i_q = 0; i_q < q; ++i_q) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		cnt[a]++;
		cnt[b]++;
		if (depth[a] < depth[b]) swap(a, b);
		int d = depth[a] - depth[b];
		for (int i = 0; i < LOG; ++i) {
			if (d & (1 << i)) {
				a = anc[a][i];
			}
		}
		if (a == b) {
			cnt[a] -= 1;
			if (par[a] != -1) {
				cnt[par[a]] -= 1;
			}
			ans[a]++;
			continue;
		}
		for (int i = LOG - 1; i >= 0; --i) {
			if (anc[a][i] != anc[b][i]) {
				a = anc[a][i];
				b = anc[b][i];
			}
		}
		int lca = par[a];
		cnt[lca] -= 1;
		if (par[lca] != -1) {
			cnt[par[lca]] -= 1;
		}
		ans[lca]++;
	}

	sort(dep.begin(), dep.end());

	for (int i = 0; i < n; ++i) {
		int v = dep[i].s;
		ans[v] += cnt[v];
		if (par[v] != -1) {
			ans[par[v]] += ans[v];
			cnt[par[v]] += cnt[v];
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << cnt[i] << " ";
	}

	return 0;
}

