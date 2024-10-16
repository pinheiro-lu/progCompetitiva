#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<ll> x(n), y(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	long double ans = sqrt(x[0]*x[0] + y[0]*y[0]);

	for (int i = 0; i < n-1; ++i) {
		ans += sqrt((x[i]-x[i+1])*(x[i]-x[i+1]) + (y[i]-y[i+1])*(y[i]-y[i+1]));
	}

	ans += sqrt(x[n-1]*x[n-1] + y[n-1]*y[n-1]);

	cout << fixed << setprecision(7) << ans << '\n';


}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
