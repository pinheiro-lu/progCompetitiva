#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int x[100'010];
void solve() {
	int n; cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}

	sort (x, x+n);
/*	for (int i = 0; i < n; ++i) {
		cout << x[i] << ' ';
	}
	cout << '\n';
	*/
	double ans;

	if (n == 5) {
		ans = max( (x[n-1] + x[n-3]) / 2.0 -  (x[1] + x[0]) / 2.0,  (x[n-1] + x[n-2]) / 2.0 -  (x[2] + x[0]) / 2.0);
		cout << setprecision(10) << ans << '\n'; return;
	}
	ans =  (x[n-1] + x[n-2]) / 2.0 -  (x[1] + x[0]) / 2.0;
	cout << setprecision(10) << ans << '\n'; return;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;

	for (int i = 1; i<= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
