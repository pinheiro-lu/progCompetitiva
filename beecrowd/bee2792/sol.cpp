#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> p;

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
			st.at(2*i) += lazy.at(i);
			st.at(2*i+1) += lazy.at(i);
			lazy.at(2*i) += lazy.at(i);
			lazy.at(2*i+1) += lazy.at(i);
		}
		lazy.at(i) = 0;
	}

	int query(int i, int l, int r, int a, int b) {
		propagate(i, l, r);
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

	void upd_range(int i, int l, int r, int a, int b, int x) {
		propagate(i, l, r);
		if (l > b || a > r) return;
		if (l >= a && b >= r) {
			lazy.at(i) += x;
			st.at(i) += x;
			return;
		}
		int m = (l + r) / 2;
		st.at(i) += (min(b, r) - max(a, l) + 1) * x;
		upd_range(i*2, l, m, a, b, x);
		upd_range(i*2+1, m+1, r, a, b, x);
	}

};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	p.resize(n);
	for (int i = 0; i < n; ++i) p.at(i) = i;
	SegTree st([](int a, int b) { return a == -1? b : b == -1 ? a : a + b; });
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		cout << 1 + st.query(1, 0, n-1, x, x);
		if (i < n-1) cout << " ";
		st.upd_range(1, 0, n-1, x, n-1, -1);
	}
	cout << "\n";


	return 0;
}
