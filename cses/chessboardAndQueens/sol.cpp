#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool blocked[8][8];
vector<bool> cols(8), diag1(15), diag2(15);
int ans;

void place (int lin, int col) {
	if(col == 8) return;
	if(lin == 8) {
		++ans;
		return;
	}
	else if(cols[col] || blocked[lin][col] || diag1[lin-col+7] || diag2[lin+col]) place(lin, col+1);
	else {
		cols[col] = true;
		diag1.at(lin-col+7) = true;
		diag2[lin+col] = true;
		place(lin+1, 0);
		cols[col] = false;
		diag1[lin-col+7] = false;
		diag2[lin+col] = false;
		place(lin, col+1);
	}
}

void solve() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			char c;
			cin >> c;
			if (c == '*') {
				blocked[i][j] = true;
			}
		}
	}

	place(0,0);

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
