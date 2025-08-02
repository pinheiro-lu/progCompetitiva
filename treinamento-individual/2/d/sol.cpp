#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e4;

array<array<bool, N>, N> adj;
array<bool, N> vis;

void dfs(int u) {
	vis[u] = true;
	for (int v = 0; v < N; ++v) {
		if (adj[u][v] && !vis[v]) {
			dfs(v);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int n = s.size();

	for (int i = 0; i < n; ++i) {
		int j = 1;
		while (i + j < n && i - j >= 0 && s[i + j] == s[i - j]) {
			adj[i - j][i + j] = adj[i + j][i - j] = true;
			j++;
		}
	}

	for (int i = 1; i < n; ++i) {
		int j = 0;
		while (i + j < n && i - j - 1 >= 0 && s[i + j] == s[i - j - 1]) {
			adj[i - j - 1][i + j] = adj[i + j][i - j - 1] = true;
			j++;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			dfs(i);
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
