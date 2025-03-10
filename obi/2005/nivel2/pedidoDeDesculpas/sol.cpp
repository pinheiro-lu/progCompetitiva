#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int c, f;

vector<pair<int, int>> fra;
vector<vector<int>> dp;

int solve (int idx, int s) {
	if (idx == f && s >= 0) return 0;
	if (s < 0) return INT_MIN;
	if (dp.at(idx).at(s) != -1) return dp.at(idx).at(s);
	return dp.at(idx).at(s) = max(solve(idx+1, s), fra.at(idx).second + solve(idx+1, s-fra.at(idx).first));
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt = 1;

	while (true) {
		cin >> c >> f;
		if (!c) break;
		fra.resize(f);
		dp.assign(f, vi(c+1, -1));
		for (auto &[a, b] : fra) {
			cin >> a >> b;
		}

		cout << "Teste " << cnt++ << '\n';
		cout << solve(0, c) << "\n\n";
	}



	return 0;
}
