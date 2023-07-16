#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;

	ll a = -1e10, b=-1e10, c=1e10, d=1e10;

	for (int i = 0 ; i < n; i++) {
		ll x;
		cin >> x;
		if (x > b) {
			b = x;
			if (b > a) swap(a,b);
		} 
		if (x < c) {
			c = x;
			if (c < d) swap(c,d);
		}
	}

	cout << max(a*b, c*d) << '\n';

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}

