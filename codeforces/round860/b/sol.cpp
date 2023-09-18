#include <bits/stdc++.h>

using namespace std;

#define N 50009

void solve() {
	int m;

	cin >> m;

	unordered_set<int> s[m];
	int num[N] = {0};
	bool valid = true;

	for (int i = 0; i < m; ++i) {
		int n; cin >> n;
		for (int j = 0; j < n; ++j) {
			int x; cin >> x;
			s[i].insert(x);
			num[x] = i;
		}
	}
	int p[m] = {0};
	for (int i = 0; i < m; ++i) {
		for (int x : s[i]) {
			if (num[x] == i) {
				p[i] = x;
				break;
			}
		}
		if (!p[i]) {
			cout << "-1\n";
			return;
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << p[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;

	cin >> t;

	while (t--) solve();

	return 0;
}
