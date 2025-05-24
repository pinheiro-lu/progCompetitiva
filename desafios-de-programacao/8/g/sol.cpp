#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 100;

array<array<int, N>, N> grid, dp;
int n, m;

int dfs(int i, int j) {
	if (i >= n || j >= m) {
		return 1;
	}
	if (dp[i][j]) {
		return dp[i][j];
	}
	if (i == n - 1 && j == m - 1) {
		return dp[i][j] = grid[i][j];
	}
	return dp[i][j] = max(gcd(grid[i][j], dfs(i + 1, j)), gcd(grid[i][j], dfs(i, j + 1)));
}
		
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;

	while (tt--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
			}
		}

		cout << dfs(0, 0) << '\n';
	}


	return 0;
}
