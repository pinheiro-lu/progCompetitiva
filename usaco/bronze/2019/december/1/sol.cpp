#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k;

	cin >> k >> n;
	int soma = 0;
	int sessions[k][n];

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> sessions[i][j];
			--sessions[i][j];
		}
	}

	int better[n][n]{};

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int l = j+1; l < n; ++l) {
				better[sessions[i][j]][sessions[i][l]]++;
			}
		}
	}
	
	int sol = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (better[i][j] == k) sol++;
		}
	}


	cout << sol << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	while (t--) solve();

	return 0;
}
