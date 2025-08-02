#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 3000, R = 100000;

array<int, N> dsu_link, sz;
array<tuple<int, int, int>, R> edges;

int find(int x) {
	if (dsu_link[x] != x) {
		dsu_link[x] = find(dsu_link[x]);
	}
	return dsu_link[x];
}

void unite (int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	dsu_link[b] = a;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cout << "Case "<< t << '\n';
		int n, r;
		cin >> n >> r;
	
		for (int i = 0; i < r; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u--; v--;
			edges[i] = {w, u, v};
		}
		sort(edges.begin(), edges.begin() + r);
		int q;
		cin >> q;
		while (q--) {	
			for (int i = 0; i < n; i++) {
				dsu_link[i] = i;
				sz[i] = 1;
			}
			int k, t;
			cin >> k >> t;
			--k, --t;
			for (int i = 0; i < r; ++i) {
				auto [w, u, v] = edges[i];
				unite(u, v);
				if (find(k) == find(t)) {
					cout << w << '\n';
					break;
				}
			}
		}
		cout << '\n';
	}


	return 0;
}
