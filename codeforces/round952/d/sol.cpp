#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<char>> g;

void solve() {
	cin >> n >> m;

	g.assign(n, vector<char>(m));

	int col = -1, row = -1;
	int max_row = 0;

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			cin >> g.at(i).at(j);
			if (col == -1 && g.at(i).at(j) == '#') col = j;
			if (g.at(i).at(j) == '#') cnt++;
		}
		if (cnt > max_row) {
			max_row = cnt;
			row = i;
		}

	}
	++row, ++col;

	cout << row << " " << col << endl;

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
