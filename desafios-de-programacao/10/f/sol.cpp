#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5, LOGN = 19;

array<vi, N> adj;
array<int, N> r, ans, depth, cnt_dep;
array<array<int, N>, LOGN> up;
array<vector<pair<int, int>>, N> queries;

int n, m;

void dfs(int v) {
	if (r[v] == -1) {
		depth[v] = 0;
	} else {
		depth[v] = depth[r[v]] + 1;
	}
	cnt_dep[depth[v]]++;
	vi aux;
	for (auto [_, p] : queries[v]) {
		aux.push_back(cnt_dep[p+depth[v]]);
	}
	for (int u : adj[v]) {
		dfs(u);
	}
	for (int i = 0; i < aux.size(); ++i) {
		//cerr << "v: " << v + 1<< ", aux[i]: " << aux[i] << ", cnt_dep[p+d]: " << cnt_dep[queries[v][i].s+depth[v]] << endl;
		ans[queries[v][i].f] = cnt_dep[queries[v][i].s + depth[v]] - aux[i] - 1;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		r[i] = x;
		if (x != -1){
			adj[x].push_back(i);
		}
	}

	for (int i = 0; i < n; ++i) up[0][i] = r[i];

	for (int i = 1; i < LOGN; ++i) {
		for (int j = 0; j < n; ++j) {
			if (up[i - 1][j] == -1) {
				up[i][j] = -1;
			} else {
				up[i][j] = up[i - 1][up[i - 1][j]];
			}
		}
	}

	cin >> m;

	for (int i = 0; i < m; ++i) {
		int v, p;
		cin >> v >> p;
		--v;
		for (int j = 0; j < LOGN; ++j) {
			if (p & (1 << j)) {
				cerr << "v: " << v << endl;
				v = up[j][v];
				
			}
		}
		if (v == -1) {
			ans[i] = 0;
			continue;
		}
		queries[v].push_back({i, p});
	}

	for (int i = 0; i < n; ++i) {
		if (r[i] == -1) {
			dfs(i);
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << ' ';
	}

	return 0;
}
