#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<vector<char>> a(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int calc = min((i < n/2 ? +n/2-1-abs(i-n/2+1) : n/2-abs(i-n/2+1)) % 4, (j < n/2 ? +n/2-1-abs(j-n/2+1) : n/2-abs(j-n/2+1)) % 4);
			switch (calc) {
				case 0:
				//a.at(i).at(j) = '0';
				break;
				case 1:
				//a.at(i).at(j) = '1';
				swap(a.at(i).at(j), a.at(j).at(n-1-i));
				break;
				case 2:
				//a.at(i).at(j) = '2';
				swap(a.at(i).at(j), a.at(n-i).at(n-j));
				break;
				case 3:
				//a.at(i).at(j) = '3';
				swap(a.at(i).at(j), a.at(n-j).at(i));
				break;
				default:
				cerr << calc << endl;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << a[i][j];
		cout << endl;
	}

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
