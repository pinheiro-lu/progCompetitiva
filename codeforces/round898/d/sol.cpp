#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int ans = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'B') {
			++ans;
			for (int j = 1; j < k; ++j) ++i;
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
