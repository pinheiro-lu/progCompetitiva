#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

#define int long long

const int N = 2001;
const int MOD = 998244353;

array<array<char, N>, N> grid;
array<array<array<int, N>, N>, 2> dp;

int n, m, d;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> m >> d;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j <= n; ++j) {
				for (int k = 0; k <= m; ++k) {
					dp[i][j][k] = 0;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> grid[i][j];
			}
		}

		for (int i = 1; i <= m; ++i) {
			if (grid[1][i] == 'X') {
				dp[1][1][i] = 1;
			}
		}
		partial_sum(dp[1][1].begin() + 1, dp[1][1].begin() + m + 1, dp[1][1].begin() + 1);

		for (int i = 1; i <= m; ++i) {
			if (grid[1][i] == 'X')dp[0][1][i] = (dp[1][1][min(i+d, m)] - dp[1][1][max(0LL, i-d-1)] - dp[1][1][i] + dp[1][1][i-1];
		}

		partial_sum(dp[0][1].begin() + 1, dp[0][1].begin() + m + 1, dp[0][1].begin() + 1);

		for (int j = 2; j <= n; ++j) {
			for (int i = 1; i >= 0; --i) {
				for (int k = 1; k <= m; ++k) {
					if (grid[j][k] == 'X') {
						int dx = d-1;
						if (!i) dp[i][j][k] = (dp[1][j][min(k+d, m)] - dp[1][j][max(0LL, k-d-1)] - dp[1][j][k] + dp[1][j][k-1] + MOD) % MOD;
						else {
							dp[i][j][k] += dp[0][j-1][min(k+dx, m)] - dp[0][j-1][max(0LL, k-dx-1)] + MOD;
							dp[i][j][k] %= MOD;
							dp[i][j][k] += dp[1][j-1][min(k+dx, m)] - dp[1][j-1][max(0LL, k-dx-1)] + MOD;
							dp[i][j][k] %= MOD;
						}
					}
				}
				if (i) partial_sum(dp[1][j].begin() + 1, dp[1][j].begin() + m + 1, dp[1][j].begin() + 1, [](int a, int b) { return (a + b) % MOD; });
			}
			partial_sum(dp[0][j].begin() + 1, dp[0][j].begin() + m + 1, dp[0][j].begin() + 1, [](int a, int b) { return (a + b) % MOD; });
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				//cerr << dp[0][i][j] << ' ';
			}
			//cerr << '\n';
		}
		//cerr << "------------------------\n";
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				//cerr << dp[1][i][j] << ' ';
			}
			//cerr << '\n';
		}

		cout << (dp[0][n][m] + dp[1][n][m]) % MOD << '\n';
	}

	return 0;
}
