#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, y, z;
ll k;
vector<ll> factors;

void solve() {
	cin >> x >> y >> z;
	cin >> k;

	ll temp_x = x, temp_y = y, temp_z = z;
	x = min({x, y, z});
	z = max({temp_x, temp_y, temp_z});
	y = temp_x + temp_y + temp_z - x - z;
	
	for (ll i = 1; i <= max({x, y, z}); ++i) {
		if (k % i == 0) {
			factors.push_back(i);
			//cerr << factors.back() << endl;
		}
	}

	ll ans = 0;
	for (ll i = 0; i < factors.size() && factors.at(i) <= x; ++i) {
		//cerr << "i: " << factors.at(i) << endl;
		for (ll j = i; j < factors.size() && factors.at(j) <= y && factors.at(i) * factors.at(j) <= k; ++j) {
			//cerr << "i: " << factors.at(i) << " j: " << factors.at(j) << endl;
			for (ll l = j; l < factors.size() && factors.at(l) <= z && factors.at(i) * factors.at(j) * factors.at(l) <= k; ++l) {
				//cerr << "i: " << factors.at(i) << " j: " << factors.at(j) << " l: " << factors.at(l) << endl;
				if (factors.at(i) * factors.at(j) * factors.at(l) == k) {
					ans = max(ans, (x-factors.at(i)+1)*(y-factors.at(j)+1)*(z-factors.at(l)+1));
				}
			}
		}
	}

	cout << ans << endl;
	factors.clear();
	

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
