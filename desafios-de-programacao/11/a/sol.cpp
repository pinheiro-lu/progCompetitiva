#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5;

int mx = 0, num;

array<int, N> dsu_link, sz;

int find(int a) {
	if (dsu_link[a] != a) {
		dsu_link[a] = find(dsu_link[a]); // Path compression
	}
	return dsu_link[a];
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return; // Already in the same set
	--num;
	if (sz[a] < sz[b]) {
		swap(a, b);
	}
	dsu_link[b] = a; // Union by sz
	sz[a] += sz[b];
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	num = n;

	for (int i = 0; i < n; i++) {
		dsu_link[i] = i;
		sz[i] = 1;
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		unite(a, b);
		mx = max(mx, sz[find(a)]);
		cout << num << " " << mx << "\n";
	}

	return 0;
}
