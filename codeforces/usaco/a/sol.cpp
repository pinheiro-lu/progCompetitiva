#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;

	int x[n], y[n];

	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> y[i];
	}

	int mx = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int aux = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			mx = max(aux, mx);
		}
	}

	cout << mx << '\n';
			

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	while (t--) solve();

	return 0;
}
