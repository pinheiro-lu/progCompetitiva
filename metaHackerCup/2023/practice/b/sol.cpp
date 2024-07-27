#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int r, c, a, b;
	cin >> r >> c >> a >> b;

	cout << ((r > c) ? "YES\n" : "NO\n");
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	for (int i = 1; i <=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
