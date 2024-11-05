#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> p;

struct SegTree {
	vector<int> st;
	int (*comp)(int, int);
	void build(int i, int l, int r) {
		if (l == r) st.at(i) = p.at(l);
		else {
			int m = (l + r) / 2;
			build(2*i, l, m);
			build(2*i+1, m+1, r);
			st.at(i) = comp(st.at(2*i), st.at(2*i+1));
		}
	}

	SegTree(int (*comp)(int, int)) : comp(comp) {
		st.resize(4*n);
		build(1, 0, n-1);
	}

	int query(int i, int l, int r, int a, int b) {
		if (l > b || a > r) return -1;
		if (l >= a && b >= r) return st.at(i);
		int m = (l + r) / 2;
		return comp(query(i*2, l, m, a, b), query(i*2+1, m+1,r, a, b));
	}

	void update(int i, int l, int r, int j, int x) {
		if (l > j || r < j) return;
		if (l == r) st.at(i) = x;
		else {
			int m = (l + r)/2;
			update(i*2, l, m, j, x);
			update(i*2+1, m+1, r, j, x);
			st.at(i) = comp(st.at(2*i), st.at(2*i+1));
		}
	}
};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> n) {
		p.resize(n);
		for (int i = 0; i < n; ++i) cin >> p.at(i);
		SegTree st_max([](int a, int b) { return a == -1 ? b : b == -1? a : max(a, b); });
		SegTree st_min([](int a, int b) { return a == -1 ? b : b == -1? a : min(a, b); });

		int q; cin >> q;
		while (q--) {
			int a, b, c;
			cin >> a >> b >> c;
			--b;
			if (a == 1) {
				st_max.update(1, 0, n-1, b, c);
				st_min.update(1, 0, n-1, b, c);
			} else {
				--c;
				cout << st_max.query(1, 0, n-1, b, c) - st_min.query(1, 0, n-1, b, c) << '\n';
			}
		}
	}
	return 0;
}