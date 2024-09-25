#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int a, b, x, y;
	cin >> a >> b >> x >> y;

	if (y < b) {
		swap(a, x);
		swap(b, y);
	}

	if (a > x) {
		cout << y - x << '\n';
	} else if (b < x) {
		cout << b-a + y-x << '\n';
	} else {
		cout << y - a << '\n';
	}

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	while (t--) solve();

	return 0;
}
