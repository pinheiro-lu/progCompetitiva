#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int score[8][8];
int ans;
int rw, ld, rd;

void backtrack(int c, int sc) {
	if (c == 8) ans = max(ans, sc);
	for (int r = 0; r < 8; ++r) {
		if (rw & (1 << r) || ld & (1 << (r-c+7)) || rd & (1 << (r + c))) continue;
		rw |= (1 << r);
		ld |= (1 << (r-c+7));
		rd |= (1 << (r+c));
//		cout << hex << rw << ' ' << ld << ' ' << rd << '\n';
//		cout << sc << '\n';
		backtrack(c + 1, sc + score[r][c]);
		rw &= ~(1 << r);
		ld &= ~(1 << (r-c+7));
		rd &= ~(1 << (r+c));
	}
}

void solve() {
	ans = rw = ld = rd = 0;
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			cin >> score[i][j];
	backtrack(0, 0);
	cout << setw(5) << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
