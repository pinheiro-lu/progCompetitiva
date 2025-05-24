#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n, m;

const int M = 5001;

array<array<pair<int,int>, M>, M> pref;
array<array<int, M>, M> dp;

int solve(int idx, int itl) {
	if (idx > m) return 0;
	if (dp[idx][itl] != -1) return dp[idx][itl];
	int str = idx - itl;
	int ans = 0;
	ans += pref[idx][itl].f;
	ans += pref[idx][str].s;
	return dp[idx][itl] = ans + max(solve(idx+1, itl+1), solve(idx+1, itl));
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i <= m; ++i)
		for (int j = 0; j <= m; ++j)
			dp[i][j] = -1;

	int i = 0;

	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		if (x > 0) {
			pref[i][x].f++;
		} else if (x < 0) {
			pref[i][-x].s++;
		} else {
			for (int k = 1; k <= m; ++k) {
				pref[i][k].f += pref[i][k-1].f;
				pref[i][k].s += pref[i][k-1].s;
			}
			i++;
		}
	}
	for (int k = 1; k <= m; ++k) {
		pref[i][k].f += pref[i][k-1].f;
		pref[i][k].s += pref[i][k-1].s;
	}

	cout << solve(0, 0) << '\n';

	return 0;
}

