#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < 4; ++j) {
			if (s[j] == '#') {
				a[i] = j+1;
			}
		}
	}

	reverse(a, a +n);

	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
