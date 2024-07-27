#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;
	int a[100], b[100];
	int last = 0;

	for (int i = 0 ; i < n; ++i) {
		int x, y; cin >> x >> y;
		for (int j = last; j < last + x; ++j) {
			a[j] = y;
		}
		last += x;
	}
	last = 0;
	for (int i = 0 ; i < m; ++i) {
		int x, y; cin >> x >> y;
		for (int j = last; j < last + x; ++j) {
			b[j] = y;
		}
		last += x;
	}

	int soma = 0;

	for (int i = 0; i < 100; ++i) {
		soma = max(soma, b[i] - a[i]);
	}

	cout << soma << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen ("speeding.in", "r", stdin);
	freopen ("speeding.out", "w", stdout);

	while (t--) solve();

	return 0;
}
