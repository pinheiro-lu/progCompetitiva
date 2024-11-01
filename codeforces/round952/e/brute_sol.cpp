#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, y, z;
ll k;

void solve() {
	cin >> x >> y >> z;
	cin >> k;

	ll temp_x = x, temp_y = y, temp_z = z;
	x = min({x, y, z});
	z = max({temp_x, temp_y, temp_z});
	y = temp_x + temp_y + temp_z - x - z;
	
	ll ans = 0;
	for (ll i = 1; i <= x; ++i) {
		//cerr << "i: " << factors.at(i) << endl;
		for (ll j = i; j <= y; ++j) {
			//cerr << "i: " << factors.at(i) << " j: " << factors.at(j) << endl;
			for (ll l = j; l <= z; ++l) {
				if (i * j * l == k) {
					cerr << "i: " << i << " j: " << j << " l: " << l << endl;
					ans = max(ans, (x-i+1)*(y-j+1)*(z-l+1));
				}
			}
		}
	}

	cout << ans << endl;
	

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
