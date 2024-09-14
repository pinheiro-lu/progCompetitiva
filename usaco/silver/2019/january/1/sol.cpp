#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << 1 << '\n';
		return;
	}
	if (n == 2) {
		cout << 2 << '\n';
		return;
	}
	cout << 3 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);

	while (t--) solve();

	return 0;
}
