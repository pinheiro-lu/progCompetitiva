#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> d, p;
vector<vector<int>> dp;

int solve (int i, int t) {
	if (i == d.size()) return 0;
	if (dp.at(i).at(t) != -1) return dp.at(i).at(t);

	if (t < d.at(i) || p.at(i) == 0) return solve(i + 1, t);

	return dp.at(i).at(t) = max({solve(i + 1, t), solve(i + 1, t - d.at(i)) + p.at(i), solve(i, t - d.at(i)) + p.at(i)});
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, t;
	int cnt = 1;

	cin >> n;

	while (n) {
		d.resize(n);
		p.resize(n);
		cin >> t;
		dp.assign(n, vector<int>(t + 1, -1));
		for(int i = 0; i < n; ++i) {
			cin >> d.at(i) >> p.at(i);
		}

		cout << "Instancia " << cnt++ << '\n';
		cout << solve(0, t) << '\n';
		cout << '\n';


		cin >> n;
	}


	return 0;
}
