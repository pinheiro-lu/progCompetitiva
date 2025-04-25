#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int INF = 1e6;
const int N = 2e5 + 5;

array<int, N> dp;

int n, m, k;
string riv;

int solve(int i) {
	if (i >= n+1) return 0;
	if (dp[i] != -1) return dp[i];
	switch (riv[i]) {
		case 'C':
			return dp.at(i) = INF;
		case 'W':
			return dp.at(i) = 1 + solve(i+1);
		case 'L':
			int ans = INF;
			for (int j = 1; j <= m; ++j) {
				ans = min(ans, solve(i+j));
			}
			return dp.at(i) = ans;
	}
	cerr << "man " << i << " " << riv[i] << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n >> m >> k;
		cin >> riv;
		riv.insert(0, 1,'L');
		riv.push_back('L');
		dp.fill(-1);
		cout << (solve(0) <= k ? "YES" : "NO") << '\n';
	}


	return 0;
}
