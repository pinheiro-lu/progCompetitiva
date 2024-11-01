#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll h;
int n;

ll dmg[200'001];
ll a[200'000];
int c[200'000];

ll bs(ll l, ll r) {
	if (l == r) return l;
	ll x = (l + r)/2;
	ll sum = 0;
	for (int i = 1; i <= 2e5; ++i) {
		sum += x/i * dmg[i];
	}
	if (sum >= h) return bs(l, x);
	return bs(x+1, r);
}

void solve() {
	cin >> h >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		h-=a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	for (int i = 0; i < n; ++i) {
		dmg[c[i]] += a[i];
	}

	if (h <= 0) {
		cout << "1\n";
	} else {
		cout << 1 + bs(1, 4e10) << '\n';
	}

	memset(dmg, 0, sizeof dmg);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
