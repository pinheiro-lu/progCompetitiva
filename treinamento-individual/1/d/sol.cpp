#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

#define int ll

const int N = 2e5;

array<int, N> dsu_link, dsu_size, val;
array<bool, N> vis;
set<int> ans;
array<set<int>, N> adj;

int find(int a) {
	if (dsu_link[a] == a) return a;
	dsu_link[a] = find(dsu_link[a]);
	adj[dsu_link[a]].insert(a);
	adj[dsu_link[a]].insert(adj[a].begin(), adj[a].end());
	adj[a].clear();
	return dsu_link[a];
}

void unite(int a, int b) {
	if (dsu_size[a] < dsu_size[b]) swap(a, b);
	dsu_link[b] = a;
	dsu_size[a] += dsu_size[b];
	adj[a].insert(b);
	adj[a].insert(adj[b].begin(), adj[b].end());
	adj[b].clear();
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		dsu_link[i] = i;
		dsu_size[i] = 1;
	}

	for (int i = 1; i <= q; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		--a; --b;
		if (vis[b]) {
			swap(a, b);
			d = -d;
		}
		if (a == b) {
			if (d == 0) {
				ans.insert(i);
			}
			continue;
		}
		if (vis[b] && vis[a]) {
			if (find(a) == find(b)) {
				if (val[a] - val[b] == d) {
					ans.insert(i);
				} else {
					//cerr << i << '\n';
				}
			} else {
				if (dsu_size[find(a)] < dsu_size[find(b)]) {
					swap(a, b);
					d = -d;
				}
				int up = val[a] - val[b] - d;
				val[find(b)] += up;
				for (int x : adj[find(b)]) {
					val[x] += up;
				}
				unite(find(a), find(b));
				ans.insert(i);
			}
		} else if (vis[a]) {
			val[b] = val[a] - d;
			vis[b] = true;
			ans.insert(i);
			unite(find(a), b);
		} else {
			val[a] = 0;
			val[b] = -d;
			vis[a] = vis[b] = true;
			ans.insert(i);
			unite(a, b);
		}
	}
	for (int x : ans) {
		cout << x << ' ';
	}
	return 0;
}
