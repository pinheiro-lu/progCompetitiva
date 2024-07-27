#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
char fig[8][8];
char pieces[10][8][8];

void solve() {
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> fig[i][j];
		}
	}

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; ++l) {
				cin >> pieces[i][j][k];
			}
		}
	}




}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("bcs.in", "r", stdin);
	freopen("bcs.out", "w", stdout);

	int t = 1;

	while (t--) solve();

	return 0;
}
