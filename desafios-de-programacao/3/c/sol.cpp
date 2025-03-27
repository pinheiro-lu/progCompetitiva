
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n, k, q;
vector<vector<int>> a;

int bsl(int reg, int x) {
	int l = 0, r = n;
	while (l < r) {
		int m = (l + r) / 2;
		if (a.at(m).at(reg) < x) l = m + 1;
		else r = m;
	}
	return l-1;
}

int bsg(int reg, int x) {
	int l = 0, r = n;
	while (l < r) {
		int m = (l + r) / 2;
		if (a.at(m).at(reg) <= x) l = m + 1;
		else r = m;
	}
	//cerr << "l " << l << '\n';
	return l;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> q;

	a.resize(n, vector<int>(k));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> a[i][j];
			if (i) a.at(i).at(j) |= a.at(i-1).at(j);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			//cerr << a.at(i).at(j) << ' ';
		}
		//cerr << '\n';
	}
	//cerr << '\n';

	while (q--) {
		int m;
		cin >> m;
		int mn = 0, mx = n-1;
		while (m--) {
			int r, c;
			char o;
			cin >> r >> o >> c;
			--r;
			if (o == '<') mx = min(mx, bsl(r, c));
			else mn = max(mn, bsg(r, c));
		}
		if (mn > mx) {
			cout << "-1\n";
		} else {
			cout << mn + 1 << '\n';
		}
	}


	return 0;
}
