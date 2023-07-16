#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll x, y;

	cin >> y >> x;

	if (y > x) {
		if (~y & 1) {
			cout << y * y - x + 1 << '\n';
			return;
		}
		cout << (y-1) * (y-1) + x << '\n';
		return;
	}
	if (y < x) {
		if (x & 1) {
			cout << x * x - y + 1 << '\n';
			return;
		}
		cout << (x-1) * (x-1) + y << '\n';
		return;
	}
	cout << x * x - x + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t;

	cin >> t;

	while (t--) solve();

	return 0;
}
