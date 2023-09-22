#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int pontos = 0;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			char c; cin >> c;
			if (c == 'X') pontos += 1 + min(4.5-abs(i-4.5), 4.5-abs(j-4.5));
		}
	}

	cout << pontos << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
