#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;

	int pro = 1, mn;
	int a[n];

	for (int i = 0; i <n; ++i) {
		cin >> a[i];
	}
	sort(a, a +n);
	++a[0];
	for (int i = 0; i < n; ++i ) {
		pro *= a[i];
	}
	cout << pro << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
