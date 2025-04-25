#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n, W;
const int N = 101;
const int V = 100001;

array<array<int, V>, N> dp;
array<int, N> w, v;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < N; ++i) {
		fill(dp.at(i).begin(), dp.at(i).end(), INT_MAX);
	}
	cin >> n >> W;
	for (int i = 0; i < n; i++) {
		cin >> w[i+1] >> v[i+1];
	}

	dp.at(0).at(0) = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = v.at(i); j < V; ++j) {
			auto &ant = dp.at(i-1).at(j-v.at(i));
			if (ant > W) continue;
			dp.at(i).at(j) = min(dp.at(i).at(j), ant + w.at(i));
		}
		for (int j = 0; j < V; ++j) {
			dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(j));
		}
	}

	int ans;

	for (int i = V-1; i >= 0; --i) {
		if (dp.at(n).at(i) <= W) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';

	return 0;
}
