#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5+1;

array<vi, N> adj;
array<int, N> col;
array<bool, N> vis;

int n, m;

void dfs(int u, int p) {
	if (vis[u]) {
		return;
	}
	col[u] = col[p] ^ 1;
	//cerr << u << " " << col[u] << "\n";
	vis[u] = true;
	for (int v : adj[u]) {
		if (v == p) {
			continue;
		}
		dfs(v, u);
	}
}
		

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			col[i] = 0;
			dfs(i, i);
		}
	}

	bool pos = true;

	for (int i = 1; i <= n; ++i) {
		//cerr << i << " " << col[i] << "\n";
		for (int v : adj[i]) {
			if (col[i] == col[v]) {
				pos = false;
			}
		}
	}

	if (!pos) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		for (int i = 1; i <= n; ++i) {
			cout << col[i] + 1 << " ";
		}
		cout << "\n";
	}

	return 0;
}
