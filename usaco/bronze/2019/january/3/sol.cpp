#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

void solve() {
   	cin >> n;

	vector <string> animals(n);
	vector <set <string>> charac(n);

	for (int i = 0; i < n; ++i) {
		cin >> animals[i];
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			string s;
			cin >> s;
			charac[i].insert(s);
		}
	}
	int mx = 0;

	for (int i = 0; i < n; ++i) {
		for (auto & c : charac) {
			int rep = 0;
			if (c.begin() == charac[i].begin()) break;
			for (string s : charac[i]) {
				if (c.find(s) != c.end()) {
					rep++;
				}
			}
			mx = max(mx, rep);
		}
	}


	cout << mx + 1 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);

	while (t--) solve();

	return 0;
}
