#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int>p;

// vector<int> p: array to build the segment tree (0-indexed)
// vector<int> st: segment tree (1-indexed)
// query: O(log n)
// update: O(log n)
// build: O(n)
struct SegTree {
	vector<int> st;
	vector<int> lazy;
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
		lazy.resize(4*n);
		build(1, 0, n-1);
	}

	void propagate(int i, int l, int r) {
		if (l != r) {
			lazy.at(2*i) += lazy.at(i);
			lazy.at(2*i+1) += lazy.at(i);
		}
		st.at(i) += lazy.at(i)* (r-l+1);
		lazy.at(i) = 0;
	}

	int query(int i, int l, int r, int a, int b) {
		propagate(i, l, r);
		if (l > b || a > r) return 0;
		if (l >= a && b >= r) return st.at(i);
		int m = (l + r) / 2;
		return comp(query(i*2, l, m, a, b), query(i*2+1, m+1,r, a, b));
	}

	void upd_range(int i, int l, int r, int a, int b, int x) {
		propagate(i, l, r);
		if (l > b || a > r) return;
		if (l >= a && b >= r) {
			lazy.at(i) += x;
			return;
		}
		int m = (l + r) / 2;
		st.at(i) += (min(r, b) - max(a, l)+1) * x;
		upd_range(i*2, l, m, a, b, x);
		upd_range(i*2+1, m+1, r, a, b, x);
	}

};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> n >> m) {
		p.resize(n);
		SegTree s0([](int a, int b) {return a + b;});
		SegTree s1([](int a, int b) {return a + b;});
		SegTree s2([](int a, int b) {return a + b;});
		s0.upd_range(1, 0, n-1, 0, n-1, 1);
		for (int i = 0; i < m; ++i) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			--a, --b;
			int temp0 = s0.query(1, 0, n-1, a, b);
			int temp1 = s1.query(1, 0, n-1, a, b);
			int temp2 = s2.query(1, 0, n-1, a, b);
			if (c == 'M') {
				cerr << temp0 << ' ' << temp1 << ' ' << temp2 << '\n';
				s0.upd_range(1, 0, n-1, a, b, temp2-temp0);
				s1.upd_range(1, 0, n-1, a, b, temp0-temp1);
				s2.upd_range(1, 0, n-1, a, b, temp1-temp2);
			}
			if (c == 'C') {
				cout << temp0 << ' ' << temp1 << ' ' << temp2 << '\n';
			}
		}
		cout << '\n';
	}
	return 0;
}
