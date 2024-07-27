#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, b; 

int auxcalc(vector <pair<int, int>>& cow, int i, int f) {
	int a = cow[i].first + f;
	int ans = n;
	for (int j = 0; j < n; ++j) {
		int b = cow[j].second + 1;
		multiset <pair <int, int>> pr, sc, th, ft;
		for (int k = 0; k < n; ++k) {
			if (cow[k].first < a && cow[k].second < b) pr.insert(cow[k]);
			if (cow[k].first < a && cow[k].second > b) sc.insert(cow[k]);
			if (cow[k].first > a && cow[k].second < b) th.insert(cow[k]);
			if (cow[k].first > a && cow[k].second > b) ft.insert(cow[k]);
		}
		ans = min(ans, (int)max({pr.size(), sc.size(), th.size(), ft.size()}));
		b = cow[j].second - 1;
		pr.clear();
		sc.clear();
		th.clear();
		ft.clear();
		for (int k = 0; k < n; ++k) {
			if (cow[k].first < a && cow[k].second < b) pr.insert(cow[k]);
			if (cow[k].first < a && cow[k].second > b) sc.insert(cow[k]);
			if (cow[k].first > a && cow[k].second < b) th.insert(cow[k]);
			if (cow[k].first > a && cow[k].second > b) ft.insert(cow[k]);
		}
		ans = min(ans, (int)max({pr.size(), sc.size(), th.size(), ft.size()}));
	}
	return ans; 
}

int calc(vector <pair<int, int>>& cow, int i) {
	return min({
			auxcalc(cow, i, -1), 
			auxcalc(cow, i, +1), 
			});
}


void solve() {
	cin >> n >> b;
	vector<pair<int, int>> cow(n);

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		cow[i] = make_pair(x, y);
	}
	int mn = 100;

	for (int i = 0; i < n; ++i) {
		mn = min(mn, calc(cow, i));
	}

	cout << mn << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	while (t--) solve();

	return 0;
}
