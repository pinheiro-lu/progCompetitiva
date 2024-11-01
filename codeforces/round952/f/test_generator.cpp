#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int h = 1e5, n = 1;

	cout << h << ' ' << n << '\n';
	for (int i = 0; i < n; ++i) {
		cout << 1 << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; ++i) {
		cout << rand() % (int)2e5 << ' ';
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cout << t << '\n';
	while (t--) solve();

	return 0;
}
