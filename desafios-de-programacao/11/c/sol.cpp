#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int M = 100000;
array<pair<int, int>, M> edges;
array<int, M> query;
array<bool, M> rem;
array<int, M> dsu_link, sz;
array<int, M> ans;
int pieces;

int find(int x) {
	if (dsu_link[x] != x) {
		dsu_link[x] = find(dsu_link[x]);
	}
	return dsu_link[x];
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	pieces--;
	if (sz[a] < sz[b]) {
		swap(a, b);
	}
	dsu_link[b] = a;
	sz[a] += sz[b];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges[i] = {u, v};
	}
	for (int i = 0; i < n; i++) {
		dsu_link[i] = i;
		sz[i] = 1;
	}
	pieces = n;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		x--;
		query[i] = x;
		rem[x] = true;
	}
	for (int i = 0; i < m; i++) {
		if (!rem[i]) {
			unite(edges[i].f, edges[i].s);
		}
	}
	ans[q-1] = pieces;
	for (int i = q-1; i > 0; --i) {
		int x = query[i];
		unite(edges[x].f, edges[x].s);
		ans[i-1] = pieces;
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}
