#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n, m;

const int M = 5001;

array<vi, M> ch;
array<array<pair<int,int>, M>, M> pref;
map<tuple<int, int, int>, int> dp;

int solve(int idx, int itl, int str) {
	if (idx > m) return 0;
	if (dp.count({idx, itl, str})) return dp[{idx, itl, str}];
	int ans = 0;
	for (int x : ch[idx]) {
		if (x > 0) {
			ans += itl >= x;
		} else {
			ans += -str <= x;
		}
	}
	return dp[{idx, itl, str}] = ans + max(solve(idx+1, itl+1, str), solve(idx+1, itl, str+1));
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	int i = 0;

	for (int j = 0; j < n; ++j) {
		int x;
		cin >> x;
		if (x) {
			ch[i].push_back(x);
		}
		else {
			i++;
		}
	}

	cout << solve(0, 0, 0) << '\n';

	return 0;
}
