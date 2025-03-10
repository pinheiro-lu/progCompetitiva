#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5;

int n, m;

array<int, N> p;

// array<int, N> p: array to build the segment tree (0-indexed)
// array<int, N> st: segment tree (1-indexed)
// query: O(log n)
// update: O(log n)
// build: O(n)
// N is the maximum size of the array
struct SegTree {
	array<int, 4*N> st;
	array<int, 4*N> lazy; // lazy does not hold the same type as the segment tree
	int (*comb)(int, int);
	void build(int i, int l, int r) {
		if (l == r) st.at(i) = p.at(l);
		else {
			int m = (l + r) / 2;
			build(2*i, l, m);
			build(2*i+1, m+1, r);
			st.at(i) = comb(st.at(2*i), st.at(2*i+1));
		}
	}

	SegTree(int (*comb)(int, int)) : comb(comb) {
		fill(lazy.begin(), lazy.end(), -1);
		build(1, 0, n-1);
	}

	void propagate(int i, int l, int r) {
		if (lazy.at(i) == -1) return;
		if (l != r) {
			lazy.at(2*i) = lazy.at(i);
			lazy.at(2*i+1) = lazy.at(i);
		}
		if ((l - r + 1) % 2 == 0) st.at(i) = 0;
		else st.at(i) = lazy.at(i);
		lazy.at(i) = -1;
	}

	int query(int i, int l, int r, int a, int b) {
		propagate(i, l, r);
		if (l > b || a > r) return 0; 
		if (l >= a && b >= r) return st.at(i); 
		int m = (l + r) / 2;
		return comb(query(i*2, l, m, a, b), query(i*2+1, m+1,r, a, b));
	}

	void upd_range(int i, int l, int r, int a, int b, int x) { // not the more efficient way to update a range
		propagate(i, l, r);
		if (l > b || a > r) return;
		if (l >= a && b >= r) {
			lazy.at(i) = x;
			propagate(i, l, r);
			return;
		}
		int m = (l + r) / 2;
		upd_range(i*2, l, m, a, b, x);
		upd_range(i*2+1, m+1, r, a, b, x);
		st.at(i) = comb(st.at(2*i), st.at(2*i+1));
	}
};
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> p.at(i);
	}

	SegTree st([](int a, int b) { return a ^b; });

	for (int i = 0; i < m; ++i) {
		int a, b, x; cin >> a >> b >> x;
		--a, --b;
		st.upd_range(1, 0, n-1, a, b, x);
		int ans = st.query(1, 0, n-1, 0, n-1); 
		if (ans != 0) cout << "Possivel\n";
		else cout << "Impossivel\n";
	}


	return 0;
}
