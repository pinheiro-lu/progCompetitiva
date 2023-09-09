#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n, x, y; cin >> n >> x >> y;
	ll com = n/lcm(x, y);

	ll qtdX = n/x - com;
	ll qtdY = n/y - com;

	ll ans = (n-qtdX+1+n)*qtdX/2 - (1+qtdY)*qtdY/2;

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
