#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool win(int a, int b) {
	return a > b;
}

void solve() {
	int a0, a1, b0, b1;

	cin >> a0 >> a1 >> b0 >> b1;

	int ans = 0;

	if ((win(a0, b0) && !win(b1,a1)) || (!win(b0, a0) && win(a1,b1))) ++ans;
	if ((win(a0, b1) && !win(b0,a1)) || (!win(b1, a0) && win(a1,b0))) ++ans;
	if ((win(a1, b0) && !win(b1,a0)) || (!win(b0, a1) && win(a0,b1))) ++ans;
	if ((win(a1, b1) && !win(b0,a0)) || (!win(b1, a1) && win(a0,b0))) ++ans;

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
