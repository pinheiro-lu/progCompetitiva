#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, x; cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort (a, a+n);

	int l = 1, r = x+a[n-1];
	int h;

	while (l < r) {
		h = (l + r) / 2;

		int g = 0, i = 0;

		while (g <= x && i < n && a[i] < h) {
			g += h-a[i];
			++i;
		}
		if (g < x) {
			l = h+1;
		} else if (g > x) {
			r = h-1;
		} else {
			break;
		}
	}
	
	int g = 0, i = 0;
	h = r;
	while (i < n && a[i] < h) {
		g += h-a[i];
		++i;
	}
	if (g > x) --r;
	cout << r << '\n';
			
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
