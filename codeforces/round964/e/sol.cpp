#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int l, r;

	cin >> l >> r;

	int ans = 0, exp;
	for (exp = 0;;exp++) {
		if (pow(3, exp) <= l && l < pow(3, exp + 1)) {
			ans += 2 * (exp + 1);
			break;
		}
	}
//	cerr << "ans " << ans << '\n';
//	cerr << "exp " << exp << '\n';
	++l;

	for (;; ++exp) {
		if (pow(3, exp+1) <= r) {
			ans += (pow(3, exp+1) - l) * (exp + 1);
			l = pow(3, exp+1);
		} else {
			ans += (r - l + 1) * (exp + 1);
			break;
		}
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
