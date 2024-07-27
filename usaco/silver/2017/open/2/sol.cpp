#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;

	string spotty[n], plain[n];

	for (int i=0; i < n; ++i) {
		cin >> spotty[i];
	}
	for (int i=0; i < n; ++i) {
		cin >> plain[i];
	}

	int sum = 0;

	for (int i = 0; i < m; ++i) {
		for (int j = i+1; j < m; ++j) {
			for (int k = j + 1; k < m; ++k) {
				set <string> s;
				for (int l = 0; l < n; ++l) {
					string aux{};
					aux.append(1,spotty[l][i]);
					aux.append(1,spotty[l][j]);
					aux.append(1,spotty[l][k]);
					s.insert(aux);
				}
				bool rep = false;
				for (int l = 0; l < n; ++l) {
					string aux{};
					aux.append(1,plain[l][i]);
					aux.append(1,plain[l][j]);
					aux.append(1,plain[l][k]);
					if (s.find(aux) != s.end()) {
						rep = true;
						break;
					}
				}
				if (!rep) ++sum;
			}
		}
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
