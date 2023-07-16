#include <bits/stdc++.h>

using namespace std;

#define N 50009

void solve() {
	int m;

	cin >> m;
	
	vector<int> n(m);
	vector<vector<pair<int, bool>>> a(m);

	vector<pair<int, int>> b(N, make_pair(-1,-1));

	for (int i = 0; i < m; i++) {
		cin >> n[i];
		a[i].resize(n[i]);
		for (int j = 0; j < n[i]; j++) {
			cin >> a[i][j].first;
			a[i][j].second = true;
			if (b[a[i][j].first].first != -1) {
				a[b[a[i][j].first].first][b[a[i][j].first].second].second = false;
			}
			b[a[i][j].first].first = i;
			b[a[i][j].first].second = j;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n[i]; j++) {
			if (a[i][j].second) {
				continue;
			}
		}
		cout << "-1\n";
		return;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n[i]; j++) {
			if (a[i][j].second) {
				cout << a[i][j].first << ' ';
				continue;
			}
		}
	}
	cout << '\n'; 



}

int main() {
	int t;

	cin >> t;

	while (t--) solve();

	return 0;
}
