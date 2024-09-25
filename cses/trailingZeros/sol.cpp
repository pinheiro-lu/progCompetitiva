#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	
	int sol = 0;
	for (int x = 5; x <= n; x *= 5) {
		sol += n / x;
	}
	cout << sol << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
