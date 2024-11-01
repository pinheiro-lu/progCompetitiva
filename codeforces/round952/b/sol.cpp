#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

int sum(int x) {
	int res = 0;
	for (int k = 1; k * x <= n; ++k) {
		res += k * x;
	}
	return res;
}

void solve() {
	cin >> n;
	int best = 0;
	int ans = 0;
	for (int x = 2; x <= n; ++x) {
		if (sum(x) > best) {
			best = sum(x);
			ans = x;
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
