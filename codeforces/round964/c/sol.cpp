#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, s, m;

	cin >> n >> s >> m;

	bool ans = false;

	int last = 0;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		if (l-last >= s) {
			ans = true;
		}
		last = r;
	}

	if (m-last >= s) {
		ans = true;
	}

	cout << (ans ? "YES" : "NO") << '\n';


}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
