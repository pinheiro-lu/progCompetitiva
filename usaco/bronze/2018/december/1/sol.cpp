#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int m[3], c[3];

	for (int i = 0; i < 3; ++i) {
		cin >> c[i] >> m[i];
	}


	for (int i = 0; i < 100; ++i) {
		int j = i % 3;
		int k = (j + 1) % 3;

		m[k] += m[j];
		if (m[k] > c[k]) {
			m[j] = m[k] - c[k];
			m[k] = c[k];
		} else {
			m[j] = 0;
		}
		
	}

	for (int i = 0; i < 3; ++i) {
		cout << m[i] << '\n';
	}

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	int t = 1;

	while (t--) solve();

	return 0;
}
