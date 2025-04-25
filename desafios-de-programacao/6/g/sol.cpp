#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1001;

array<array<int, N>, N> dp;

string a, b, c;

int solve(int i, int j) {
	int k = i + j;
	if (k == c.size()) {
		return 0;
	}
	if (dp[i][j] != INT_MAX) {
		return dp[i][j];
	}
	if (i < a.size()) {
		dp.at(i).at(j) = (a.at(i) != c.at(k)) + solve(i + 1, j);
	}
	if (j < b.size()) {
		dp.at(i).at(j) = min(dp.at(i).at(j), (b.at(j) != c.at(k)) + solve(i, j + 1));
	}
	return dp.at(i).at(j);
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt;
	cin >>tt;
	while (tt--) {
		for (int i = 0; i < N; i++) {
			fill(dp[i].begin(), dp[i].end(), INT_MAX);
		}
		cin >> a >> b >> c;
		cout << solve(0, 0) << '\n';
	}

	return 0;
}
