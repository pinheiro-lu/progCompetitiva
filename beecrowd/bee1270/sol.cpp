#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n;

map <string, vector<pair<int, int>>> tab;
map <string, vector<string>> adj;
map <string, vector<double>> dp;

void solve (string at, string pai) {
	for (string next : adj.at(at)) {
		if (next == pai) continue;
		solve(next, at);
	}

	if (pai.empty()) return;

	dp[pai].resize(tab.at(pai).size());
	dp[at].resize(tab.at(at).size());

	auto &ref = tab.at(pai);
	auto &me = tab.at(at);

	for (int i = 0; i < ref.size(); ++i) {
		double best = 1e9;
		for (int j = 0; j < me.size(); ++j) {
			best = min(best, dp.at(at).at(j) + sqrt((me.at(j).first-ref.at(i).first)*(me.at(j).first-ref.at(i).first)+(me.at(j).second-ref.at(i).second)*(me.at(j).second-ref.at(i).second)));
			//cerr << pai << ' ' << at << ' ' << i << ' ' << j << ' ' << best << '\n';
		}
		dp.at(pai).at(i) += best;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (true) {
		cin >> n;
		if (!n) break;
		dp.clear();
		adj.clear();
		tab.clear();

		for (int i = 0; i < n; ++i) {
			string s;
			int c;
			cin >> s >> c;

			for (int j = 0; j < c; ++j) {
				int x, y;
				cin >> x >> y;
				tab[s].push_back({x, y});
			}
		}

		for (int i = 0; i < n-1; ++i) {
			string s, r;
			cin >> s >> r;
			adj[s].push_back(r);
			adj[r].push_back(s);
		}

		if (n == 1) {
			cout << "0.0\n";
			continue;
		}

		solve(adj.begin()->first, "");
		double ans = 1e9;


		for (double res : dp.at(adj.begin()->first)) {
			ans = min(ans, res);
			//cerr << "ans " << ans << '\n';
		}

		cout << fixed << setprecision(1) << ans << '\n';

	}

	return 0;
}
