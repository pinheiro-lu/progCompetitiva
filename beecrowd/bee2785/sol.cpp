#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<vector<int>> a;
vector<vector<int>> p;
vector<vector<int>> dp;

void solve() {
	cin >> n;

	a.resize(n, vector<int>(n));

	for (auto &v : a) for (int &x: v) cin >> x;

	p.resize(n+1, vector<int>(n+1));

	for (int i = 0; i < n; ++i) {
		partial_sum(a.at(i).begin(), a.at(i).end(), p.at(i+1).begin() + 1);
	}

	dp.assign(n+1, vector<int>(n+2));

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; i + j <= n; ++j) {
			dp.at(i).at(j) = p.at(i).at(i+j) - p.at(i).at(j) + min(dp.at(i-1).at(j), dp.at(i-1).at(j+1));
			cerr << "i " << i << " j " << j << " dp " << dp.at(i).at(j) << '\n';
		}
		cerr << '\n';
	}

	cout << dp.at(n).at(0) << '\n';


	
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}