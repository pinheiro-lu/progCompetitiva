#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int a, b;
	cin >> a >> b;

	if (a < b) swap(a, b);

	int diff = a - b;
	b -= diff;
	if (b >= 0 && b % 3 == 0) cout << "YES\n";
	else cout << "NO\n";



}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
