#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+1;
	

void solve() {
	array<array<char, N>, N> pht;
	array<array<bool, N>, N> stars;
	int n, a, b;
	cin >> n >> a >> b;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			pht.at(i).at(j) = 'W';
			stars.at(i).at(j) = false;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> pht.at(i).at(j);
			ans += pht.at(i).at(j) != 'W';
		}
	}

	if (a == 1) {
		if (b == 1) {
			cout << "-1\n";
			return;
		}
		if (b == 2) {
		   	cout << "4\n";
			return;
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {


		for (int i = n; i > 0; --i) {
			for (int j = n; j > 0; --j) {
				if (pht.at(i).at(j) == 'B') {
					stars.at(i).at(j) = stars.at(i).at(j-1) = true;
					--j;
				} else if (pht.at(i).at(j) == 'G') {
					if (pht.at(i).at(j-1) == 'W') {
						stars.at(i).at(j) = true;
					} else {
						if (!stars.at(i).at(j)) stars.at(i).at(j-1) = true;
					}
				}
			}
		}

		ans = 0;
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				ans += stars.at(i).at(j);
				if (stars.at(i).at(j) && pht.at(i).at(j) == 'W') {
					cout << "-1\n";
					return;
				}
			}
		}

		cout << ans << '\n';
		return;
	}

	cout << ans << '\n';
}


signed main() {
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
