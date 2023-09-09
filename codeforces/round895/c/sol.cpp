#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int a, b, l, r;
void solve() {
	 cin >> l >> r;
	 a = b = 0;
	if (l != r) {
		a = 2;
		if ( l & 1) b = l-1;
		else b = l-2;
	} else {
		if ( ~l & 1) {
			a = 2; b = l -2;
		} else {
			for (int i = 2; i <= l/2; ++i) {
				if (gcd(i, l - i) != 1) {
					a = i; b = l -i;
					break;
				}
			}
			if (!a) {cout << "-1\n"; return;}
		}
	}
	cout << a << ' ' << b << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
