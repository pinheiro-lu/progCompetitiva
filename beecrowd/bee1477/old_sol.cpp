#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5;

int n, m;
array<array<int, 3>, N> p;

// array<int> p: array to build the segment tree (0-indexed)
// array<int> st: segment tree (1-indexed)
// query: O(log n)
// update: O(log n)
// build: O(n)
struct SegTree {
	array<array<int, 3>, 4*N> st;
	array<int, 4*N> lazy;
	array<int, 3> (*comp)(array<int, 3>, array<int, 3>);
	void build(int i, int l, int r) {
		if (l == r) st.at(i) = p.at(l);
		else {
			int m = (l + r) / 2;
			build(2*i, l, m);
			build(2*i+1, m+1, r);
			st.at(i) = comp(st.at(2*i), st.at(2*i+1));
		}
	}

	SegTree(array<int, 3> (*comp)(array<int, 3>, array<int, 3>)) : comp(comp) {
		fill(lazy.begin(), lazy.end(), 0);
		build(1, 0, n-1);
	}

	void op(array<int, 3> &s, int times) {
		array<int, 3> aux(s);
		for (int i = 0; i < 3; ++i) {
			s.at((i + times) % 3) = aux.at(i);
		}
		
	}

	void propagate(int i, int l, int r) {
		if (l != r) {
			lazy.at(2*i) += lazy.at(i);
			lazy.at(2*i+1) += lazy.at(i);
		}
		op(st.at(i), lazy.at(i));
		lazy.at(i) = 0;
	}

	array<int, 3> query(int i, int l, int r, int a, int b) {
		propagate(i, l, r);
		if (l > b || a > r) {
			//cerr << "i " << i << " l " << l << " r " << r << " st.at(i) " << st.at(i)[0] << ' ' << st.at(i)[1] << ' ' << st.at(i)[2] << '\n';
			return {0,0,0};
		}
		if (l >= a && b >= r) {
			//cerr << "i " << i << " l " << l << " r " << r << " st.at(i) " << st.at(i)[0] << ' ' << st.at(i)[1] << ' ' << st.at(i)[2] << '\n';
			return st.at(i);
		}
		int m = (l + r) / 2;
		//cerr << "i " << i << " l " << l << " r " << r << " st.at(i) " << st.at(i)[0] << ' ' << st.at(i)[1] << ' ' << st.at(i)[2] << '\n';
		return comp(query(i*2, l, m, a, b), query(i*2+1, m+1,r, a, b));
	}

	void upd_range(int i, int l, int r, int a, int b) {
		propagate(i, l, r);
		if (l > b || a > r) return;
		if (l >= a && b >= r) {
			++lazy.at(i);
			if (l != r) {
				lazy.at(2*i) += lazy.at(i);
				lazy.at(2*i+1) += lazy.at(i);
			}
			op(st.at(i), lazy.at(i));
			lazy.at(i) = 0;
			return;
		}
		int m = (l + r) / 2;
		upd_range(i*2, l, m, a, b);
		upd_range(i*2+1, m+1, r, a, b);
		st.at(i) = comp(st.at(2*i), st.at(2*i+1));
	}

};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> n >> m) {
		fill(p.begin(), p.end(), array<int, 3>{1, 0, 0});
		SegTree st([](array<int, 3>a, array<int, 3>b) {
				array<int, 3> c;
				for (int i = 0; i < 3; ++i) {
				c.at(i) = a.at(i) + b.at(i);
				}
				return c;
				});
		for (int i = 0; i < m; ++i) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			--a, --b;
			if (c == 'M') {
				st.upd_range(1, 0, n-1, a, b);
			}
			if (c == 'C') {
				array<int, 3> ans = st.query(1, 0, n-1, a, b);
				cout << ans.at(0) << ' ' << ans.at(1) << ' ' << ans.at(2) << '\n';
			}
		}
		cout << '\n';
	}
	return 0;
}

