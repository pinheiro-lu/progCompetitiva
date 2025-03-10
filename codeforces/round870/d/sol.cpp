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
		vi b(n);
		for (int &x : b) cin >> x;

		int f = 0, mi = 0;
		int sf = b[1] + b[0], m = b[0];

		int ans = sf + b[2] -2;
		for (int i = 3; i < n; ++i) {
			if (b[i-2]+i-2 > m) {
				m = b[i-2]+i-2;
				mi = i-2;
			}
			sf = max(sf, b[f]+f+b[i-1]);
			int alt = m + b[i-1];
			if (alt > sf) {
				f = mi;
				sf = alt;
			}
			ans = max(ans, sf + b[i] - i);
		}

		cout << ans << '\n';
	}



	return 0;
}
