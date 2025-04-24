#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 21;
const int MOD = 1e9 + 7;

array<int, 1<<N> dp;
array<array<bool, N>, N> adj;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}

	dp.at(0) = 1;

	for (int mask = 1; mask < (1 << n); ++mask) {
		int k = __builtin_popcount(mask);
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				if (adj[k - 1][i]) {
					dp[mask] += dp[mask ^ (1 << i)];
					dp[mask] %= MOD;
				}
			}
		}
	}

	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}
