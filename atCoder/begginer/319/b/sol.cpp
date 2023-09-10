#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;

	for(int i = 0; i <=n; ++i) {
		int j;
		for (j = 1; j <= 9; ++j) {
			if (n % j == 0 && i % (n/ j) == 0) {
				cout << j; break;
			}
		}
		if (j == 10) cout << '-';
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
