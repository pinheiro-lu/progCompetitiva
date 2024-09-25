#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll q;
map<ll, ll> mp;

void solve() {
	cin >> q;

	while (q--) {
		ll a, k;
		cin >> a >> k;
		if (a == 0) {
			ll v;
			cin >> v;
			mp[k] = v;
		} else {
			cout << (mp.count(k) ? mp[k] : 0) << '\n';
		}
	}
	
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t = 1;

	while (t--) solve();

	return 0;
}
