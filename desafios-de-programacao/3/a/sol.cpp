
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
		int l = 2, r = 999;
		while (l < r) {
			int m = (l + r) / 2;
			cout << "? " << m << " 1" << endl;
			int res;
			cin >> res;
			if (res == -1) {
				return 0;
			}
			if (res > m) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		cout << "! " << l << endl;
	}
			

	return 0;
}
