#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 500;

array<array<int, N + 1>, N + 1> dp;
/*
int solve(int a, int b) {
	if (a <= 0 || b <= 0) return 500*500; // impossible case
	if (a == b) return dp[a][b]=0;

	//cerr << a << ' ' << b << '\n';

	if (dp[a][b] != -1) return dp[a][b];

	int ans = 500*500;
	for (int i = 1; i < a; ++i) { // cut a in a-i and i
		ans = min(ans, 1 + solve(i, b) + solve(a - i, b));
	}
	for (int i = 1; i < b; ++i) { // cut b in b-i and i
		ans = min(ans, 1 + solve(a, i) + solve(a, b - i));
	}
	return dp[a][b]=ans;
}
*/

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b; cin >> a >> b;

	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j < N + 1; ++j) {
			dp[i][j] = -1;
		}
	}

//	cout << solve(a, b) << '\n';

	for (int i = 1; i <= a; ++i) {
		for (int j = 1; j <= b; ++j) {
			if (i == j) {
				dp[i][j] = 0;
			} else {
				int ans = 500*500;
				for (int k = 1; k < i; ++k) { // cut i in k and i-k
					ans = min(ans, 1 + dp[k][j] + dp[i - k][j]);
				}
				for (int k = 1; k < j; ++k) { // cut j in k and j-k
					ans = min(ans, 1 + dp[i][k] + dp[i][j - k]);
				}
				dp[i][j] = ans;
			}
		}
	}

	cout << dp[a][b] << '\n';

	return 0;
}
