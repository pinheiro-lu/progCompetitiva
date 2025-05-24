#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int MAX_DP = 114, N = 1e6+1;
const ll INF = 1e13;

array<array<ll, MAX_DP>, MAX_DP> dp;
array<int, N> gcd_a, gcd_b;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a, b;

	cin >> n >> a >> b;

	for (int i = 1; i <= n; ++i) {
		gcd_a[i] = gcd(a, i);
		gcd_b[i] = gcd(b, i);
	}
	int x;
	for (x = n; x >= 1; --x) {
		if (gcd_a[x] == 1) break;
	}
	int y;
	for (y = n; y >= 1; --y) {
		if (gcd_b[y] == 1) break;
	}
	ll ans = 0;
	for (int i = 1; i < x; ++i) {
		ans += gcd_a[i];
	}
	for (int i = 1; i < y; ++i) {
		ans += gcd_b[i];
	}
	ans += x + y - 2;

	//cerr << x << ' ' << y << '\n';
	cerr << sqrt(N) << '\n';

	for (int i = 0; i <= n-x+1; ++i) {
		dp[i].fill(INF);
	}
	dp[0][1] = dp[1][0] = 0;
	for (int i = x; i <= n; ++i) {
		for (int j = y; j <= n; ++j) {
			dp[i-x+1][j-y+1] = gcd_a[i] + gcd_b[j] + min(dp[i-x+1][j-y], dp[i-x][j-y+1]);
		}
	}
	ans += dp[n-x+1][n-y+1];

	cout << ans << '\n';

	return 0;
}
