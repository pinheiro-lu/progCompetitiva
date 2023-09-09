#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ds[1000];

void solve() {
	int n; cin >> n;

	for (int i = 1; i <= 1000; ++i) {
		ds[i] = 1000;
	}

	for (int i = 0; i < n; ++i) {
		int d, s;
		cin >> d >> s;
		ds[d] =min(ds[d], s);
	}

	int lim = 1000;
	int k;

	for (k = 1; k <= lim; ++k) {
		if (ds[k] & 1) ++ds[k];
		lim = min(lim, k + (ds[k]-2)/2);
//		cout << "lim: " << lim << '\n';
	}

	cout << lim << '\n';


}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
