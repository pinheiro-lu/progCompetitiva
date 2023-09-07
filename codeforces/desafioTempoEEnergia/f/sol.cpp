#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, d; cin >> n >> d;

	pair<int, int> pac[n];

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> y >> x;

		pac[i] = make_pair(x, y);
	}

	sort(pac, pac + n, [](auto&lhs, auto&rhs) {
		return lhs.second-rhs.second < 0; 
	});

	for (int i = 0; i < n; ++i) {
//		cout << pac[i].first << ' ' << pac[i].second << '\n';
	}
	int ans = 0, usd = 0;

	int i = 1, j = 0;
	priority_queue<int> pq;

	while (i <= d) {
		while (j < n && pac[j].second == i) {
			pq.push(pac[j].first);
			++j;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
		++i;
	}

	cout << ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}
