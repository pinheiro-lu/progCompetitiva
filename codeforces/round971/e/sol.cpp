#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

ll calc_x(ll i) {
	ll x = k*i + (i-1)*i/2 - (k*(n-i) + (n-i)*(n-1+i)/2);
	return abs(x);
}

int search(int mn, int mx) {
	int i = (mx+mn)/2;
	ll ant_x = calc_x(i-1);
	ll x = calc_x(i);
	ll pos_x = calc_x(i+1);
	if (mn >= mx) return x;
	if (ant_x >= x && x >= pos_x) {
		return search(i+1, mx);
	}
	if (ant_x <= x && x <= pos_x) {
		return search(mn, i-1);
	}
	return x;
}

void solve() {
	cin >> n >> k;

	cout << search(1, n) << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
