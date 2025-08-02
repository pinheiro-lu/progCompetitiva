#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 3e5 + 1;

array<array<ll, N>, 2> a, p;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		p[~i&1][i] = p[~i&1][i-1] + a[~i&1][i] * (i-1)*2;
		p[i&1][i] = p[~i&1][i] + a[i&1][i] * ((i-1)*2 + 1);
	}

	ll ans = max(p[0][n], p[1][n]);

	ll sub = 0, add1 = 0, add2 = 0, inc_sub = 0;

	for (int i = n; i > 0; --i) {
		add1 += a[0][i] * (i-1)*2 + a[1][i] * (2*n-1) - sub;
		add2 += a[1][i] * (i-1)*2 + a[0][i] * (2*n-1) - sub;
		inc_sub += a[0][i] + a[1][i];
		sub = inc_sub;
		ans = max(ans, i & 1 ? p[0][i-1] + add1 : p[1][i-1] + add2);
	}

	cout << ans << '\n';
	return 0;
}
