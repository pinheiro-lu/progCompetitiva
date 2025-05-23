#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int c, r, n, s;

// vector<int> p: array to build the segment tree (0-indexed)
// vector<int> st: segment tree (1-indexed)
// query: O(log n)
// update: O(log n)
// build: O(n)

vector <int> p;
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
		st.resize(4*c);
		lazy.resize(4*c);
		build(1, 0, c-1);
	}

	void propagate(int i, int l, int r) {
		if (l < r) {
			lazy.at(2*i) = comp(lazy.at(2*i), lazy.at(i));
			lazy.at(2*i+1) = comp(lazy.at(2*i+1), lazy.at(i));
		}
		//cerr << "prop " << i << ' ' << l << ' ' << r << ' ' << st.at(i) << ' ' << lazy.at(i) << endl;
		st.at(i) = comp(st.at(i), lazy.at(i)*(r-l+1));
		lazy.at(i) = 0;
	}

	int query(int i, int l, int r, int a, int b) {
		cerr << "l r st lz " << l << ' ' << r << ' ' << st.at(i) << ' ' << lazy.at(i) << endl;
		propagate(i, l, r);
		if (l > b || a > r) return 0;
		if (l >= a && b >= r) {
			return st.at(i);
		}
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
		//cerr << "updating " << i << ' ' << l << ' ' << r << ' ' << a << ' ' << b << ' ' << x << endl;
		propagate(i, l, r);
		if (l > b || a > r) return;
		if (l >= a && b >= r) {
			lazy.at(i) = comp(lazy.at(i), x);
			return;
		}
		int m = (l + r) / 2;
		int h = min(r, b) + max(a, l);
		upd_range(i*2, l, m, a, b, x);
		upd_range(i*2+1, m+1, r, a, b, x);
		st.at(i) = h*x+comp(st.at(2*i), st.at(2*i+1));
	}
		
};

vector<vector<int>> str;
SegTree *st;

int solve(int s, int r) {
	if (r == -1) return 0;
	//cerr << "lazy " << st->lazy.at(1) << endl;
	//cerr << "lazy " << st->lazy.at(1) << endl;
	st->upd_range(1, 0, c-1, s, s, -st->query(1, 0, c-1, s, s));
	cerr << "updated\n";
	int prox, proxIna = INT_MAX;
	for (int i = 0; i < c; ++i) {
		int ina;
		if (str.at(s).at(i) && ((ina = st->query(1, 0, c-1, i, i)) < proxIna)) {
			prox = i;
			proxIna = ina;
		}
	}
	for (int i = 0; i < c; ++i) {
		cerr << st->query(1, 0, c-1, i, i) << ' ';
	}
	cerr << '\n';
	int d = str.at(s).at(prox);
	cerr << "r antes " << r << " s " << st->query(1, 0, c-1, 0, c-1) << endl;
	if (d > r) {
		int sum = st->query(1, 0, c-1, 0, c-1);
		while (r--) {
			cerr << "sum " << sum << endl;
			st->upd_range(1, 0, c-1, 0, c-1, 1);
			sum += st->query(1, 0, c-1, 0, c-1);
		}
		return sum;
	}
	int sum = st->query(1, 0, c-1, 0, c-1);
	for (int i = 0; i < d; ++i) {
		st->upd_range(1, 0, c-1, 0, c-1, 1);
		sum += st->query(1, 0, c-1, 0, c-1);
	}

	cerr << "r depois " << r << " s " << st->query(1, 0, c-1, 0, c-1) << endl;
	return sum + solve(prox, r-d);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> c;
	while (c) {
		cin >> r >> n >> s;
		--s;
		str.assign(c, vector<int>(c));
		p.assign(c, 0);
		st = new SegTree([](int a, int b) { return a + b; });

		for (int i = 0; i < r; ++i) {
			int x, y, d;
			cin >> x >> y >> d;
			--x, --y;
			str.at(x).at(y) = d;
			str.at(y).at(x) = d;
		}
		for (int i = 0; i < c; ++i) {
			//cerr << str.at(i).first << ' ' << str.at(i).second << endl;
		}
		st->upd_range(1, 0, c-1, 0, c-1, 1);
		cout << solve(s, n-1) << '\n';
		cerr << '\n';

		cin >> c;
	}

	return 0;
}
