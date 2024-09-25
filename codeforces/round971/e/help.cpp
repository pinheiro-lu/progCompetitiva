#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

int x(int i) {
	int sum = 0;
	for (int j = 0; j < i; ++j) {
		sum+=k+j;
	}
	for (int j = i; j < n; ++j) {
		sum-=k+j;
	}
	return abs(sum);
}

void solve() {
	cin >> n >> k;

	int mn = x(1);
	for (int i = 1; i <= n; ++i) {
		mn = min(mn, x(i));
		cerr << i << ' ' << x(i) << '\n';
	}
	cout << mn << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;

	while (t--) solve();

	return 0;
}
