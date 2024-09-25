#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ret[2001][2001];

void solve() {
	for (int i = 0; i < 2; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x <= x2; ++x) {
			for (int y = y1; y <= y2; ++y) {
				ret[x+1000][y+1000] = i < 1;
			}
		}
	}

	int max_col = 0;
	int max_lin = 0;
	for (int i = 0; i <= 2000; ++i) {
		int lin = 0;
		for (int j = 0; j <= 2000; ++j) {
			lin += ret[i][j];
		}
		max_lin = max(lin, max_lin);
	}
	for (int i = 0; i <= 2000; ++i) {
		int col = 0;
		for (int j = 0; j <= 2000; ++j) {
			col += ret[j][i];
		}
		max_col = max(col, max_col);
	}

	cout << (max_lin * max_col) << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	while (t--) solve();

	return 0;
}
