#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		ll s = 0;
		int odd = 0, mx = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			mx = max(mx, x);
			s += x;
			odd += x % 2;
		}
		if (odd == n || odd == 0) {
			cout << mx << '\n';
		} else {
			cout << s - (odd-1) << '\n';
		}
	}

	return 0;
}
