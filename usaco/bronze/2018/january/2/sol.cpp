#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<int> start, end_;

void solve() {
	cin >> n;
	vector <int> pool(2000);

	for (int i = 1; i <= n; ++i) {
		int s, e;
		cin >> s >> e;

		start.push_back(s);
		end_.push_back(e);
		for (int j = s; j < e; ++j) {
			pool[j] += i;
		}
	}
	int maxCovers = 0;
	for (int i = 1; i <=n; ++i) {
		int s = start[i-1];
		int e = end_[i-1];
		for (int j = s; j < e; ++j) {
			pool[j] -= i;
		}
		int covers = 0;
		for (int j=0; j <= 1000; ++j) {
			if(pool[j]) covers++;
		}
		for (int j = s; j < e; ++j) {
			pool[j] += i;
		}
		maxCovers = max(maxCovers, covers);
	}

	cout << maxCovers << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	while (t--) solve();

	return 0;
}
