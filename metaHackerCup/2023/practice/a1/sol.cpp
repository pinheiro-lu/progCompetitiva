#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int s, d, k;
	cin >> s >> d >> k;

	int bn = k+1, cn = k;
	int b = 2*s + 2*d, c = s + 2*d;

	if (bn <= b && cn <= c) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;

	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}
