#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string a, b;
	cin >> a >> b;
	swap(a[0], b[0]);

	cout << a << ' ' << b << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
