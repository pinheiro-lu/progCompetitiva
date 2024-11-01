#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int ans;
vector<pair<int, int>>c;
vector<vector<int>> adj;
vector<int> dp;
vector<int> id;
set<int> vis;

void solve(int idx, int val, int pai) {
	dp.at(idx) = val;
	int my_id = id.at(idx);
	int searched = idx == c.at(my_id).first ? c.at(my_id).second : c.at(my_id).first;
	if (dp.at(searched) != -1) {
		cerr << "idx = " << idx << " searched = " << searched << '\n';
		if (vis.count(searched)) {
			ans += dp.at(idx) - dp.at(searched);
		} else {
			ans += dp.at(idx) + dp.at(searched);
		}
	}
	for (int &x : adj.at(idx)) {
		if (x == pai) continue;
		vis.insert(x);
		dp.at(x) -= val;
		solve(x, val+1, idx);
		vis.erase(x);
	}
	for (int &x : adj.at(idx)) {
		if (x == pai) continue;
		dp.at(x) += val;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	c.resize(n/2);
	adj.resize(n);
	dp.resize(n, -1);
	id.resize(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		id.at(i) = x;
		if (c.at(x).first) {
			c.at(x).second = i;
		} else {
			c.at(x).first = i;
		}
	}

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj.at(a).push_back(b);
		adj.at(b).push_back(a);
	}


	dp.at(0) = 0;
	vis.insert(0);
	for (int &x : adj.at(0)) {
		vis.insert(x);
		solve(x, 1, 0);
		vis.erase(x);
	}

	cout << ans << '\n';



	return 0;
}
