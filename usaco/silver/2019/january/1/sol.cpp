#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<set<int>> adj;
vector <int> color;

void dfs(int i, vector<int>&pai) {
	int used_color = 0;
	for (auto it = adj[i].begin(); it != adj[i].end();) {
		int x = *it;
		while ((pai[i] != -1 && color[pai[i]] == used_color) || color[i] == used_color) {
			used_color++;
		}
		pai[x] = i;
		color[x] = used_color++;
		it = adj[i].erase(it);
		adj[x].erase(i);
		dfs(x, pai);
	}
}

void solve() {
	cin >> n;
	adj.resize(n);

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[--a].insert(--b);
		adj[b].insert(a);
	}

	color.resize(n);
	for (int i = 0; i < color.size(); ++i) {
		color[i] = -1;
	}
	color[0] = 0;
	vector<int> pai(n, -1);

	dfs(0, pai);
	cout << (*max_element(color.begin(), color.end()) + 1) << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);

	while (t--) solve();

	return 0;
}
