#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve() {
	int a, b;
	int min_c = 1000;
	cin >> a >> b;

	for (int c = a; c <= b; ++c) {
		min_c = min(min_c, (c-a)+(b-c));
	}
	cout << min_c << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
