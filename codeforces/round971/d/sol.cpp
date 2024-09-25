#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

int n;

void solve() {
	cin >> n;
	set<int> zero, one;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (y == 0) {
			zero.insert(x);
		} else {
			one.insert(x);
		}
	}

	int ans = 0;
	for (int x : zero) {
		if (one.count(x)) {
			ans += n-2;
		}
		if (one.count(x+1) && zero.count(x+2)) {
			++ans;
		}
		if (one.count(x-1) && one.count(x+1)) {
			++ans;
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
