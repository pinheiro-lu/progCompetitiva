#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 100;

array<array<bool, N>, N> adj;
array<bool, N> vis;
set<int> root;

int n, m;

void dfs(int u, set<int> p) {
	vis[u] = true;
	p.insert(u);
	int cnt = 0;
	for (int v = 0; v < n; ++v) {
		if (adj[u][v]) {
			if (!vis[v]) {
				dfs(v, p);
			} else if (p.count(v)) {
				cnt++;
				if (cnt == 2) {
					root = p;
				}
			}
		}
	}
}

bool cycle = false;
void dfs2(int u, int p) {
	vis[u] = true;
	for (int v = 0; v < n; ++v) {
		if (root.count(v)) continue;
		if (adj[u][v]) {
			if (!vis[v]) {
				dfs2(v, u);
			} else if (v != p) {
				cycle = true;
				cerr << u << ' ' << p << ' ' << v << '\n';
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u][v] = adj[v][u] = true;
	}

	dfs(0, {});

	fill(vis.begin(), vis.end(), false);
	for (int u : root) {
		dfs2(u, -1);
	}

	for (int i = 0; i < n; ++i) {
		if (!vis[i]) cycle = true;
	}

	if (cycle || root.empty()) { 
		cout << "NO\n";
	} else {
		cout << "FHTAGN!\n";
	}


	return 0;
}
