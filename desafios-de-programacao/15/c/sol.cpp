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
		int n; cin >> n;
		bool ok = true;
		for (int i = 1; i <= n;++i) {
			int x; cin >> x;
			if (abs(x - i) > 1) {
				ok = false;
			}
		}
		if (ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}


	return 0;
}
