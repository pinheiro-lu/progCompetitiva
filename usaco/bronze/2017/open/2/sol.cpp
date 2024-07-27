#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;

	string s[n];
	set <char> letters[m];

	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j) {
			letters[j].insert(s[i][j]);
		}
	}

	set <char> tellers[m];

	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j) {
			tellers[j].insert(s[i][j]);
		}
	}

	int sum = 0;

	for (int i = 0; i < m; ++i) {
		bool found = false;
		for (char c : letters[i]) {
			if (tellers[i].find(c) != tellers[i].end()) {
				found = true;
			}
		}
		if (!found) ++sum;
	}

	cout << sum << '\n';


}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	while (t--) solve();

	return 0;
}
