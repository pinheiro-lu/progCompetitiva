#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int x, y, k;
	cin >> x >> y >> k;

	int moves_x = x/k;
	if (x % k) ++moves_x;
	int moves_y = y/k;
	if (y % k) ++moves_y;

	int ans;
	if (moves_x > moves_y) {
		ans = moves_x * 2 -1;
	} else {
		ans = moves_y * 2;
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
