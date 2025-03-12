#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int m, a, b, c;
		cin >> m >> a >> b >> c;
		int t = 2 * m;
		t -= min(a, m);
		t -= min(b, m);
		t -= min(c, t);
		cout << 2*m-t << '\n';
	}

	return 0;
}
