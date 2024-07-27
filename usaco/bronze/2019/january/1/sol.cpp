#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;

	int a =1, b = 2, c = 3;
	int sa = 0, sb = 0, sc = 0;

	for (int i = 0; i < n; ++i) {
		int x, y, z; cin >> x >> y >> z;
		if ( a == x ) a = y;
		else if ( a == y ) a = x;
		if ( b == x ) b = y;
		else if ( b == y ) b = x;
		if ( c == x ) c = y;
		else if ( c == y ) c = x;
		if (a == z) ++sa;
		if (b == z) ++sb;
		if (c == z) ++sc;
	}
	sa = max(sa, sb);
	cout << max (sa, sc) << '\n';



}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);

	while (t--) solve();

	return 0;
}
