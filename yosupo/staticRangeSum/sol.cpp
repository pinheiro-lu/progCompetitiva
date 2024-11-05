#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, q;
	cin >> n >> q;

	vector<ll> prefix(n+1);

	prefix.at(0) = 0;

	for (int i = 1; i <= n; ++i ) {
		int x;
		cin >> x;
		prefix.at(i) = x + prefix.at(i-1);
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << prefix.at(r) - prefix.at(l) << '\n';
	}


}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}