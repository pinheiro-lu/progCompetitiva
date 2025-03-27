
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
			int delta = (r-l)/3;
			int m1 = l + delta;
			int m2 = r - delta;
			cout << "? " << m1 << ' ' << m2 << endl;
			int res;
			cin >> res;
			if (res == -1) {
				return 0;
			}
			if (m1 * m2 == res) {
				l = m2 + 1;
			} else if ((m1+1)*(m2+1)==res) {
				r = m1;
			} else {
				l = m1 + 1;
				r = m2;
			}
		}
		cout << "! " << l << endl;
	}
			

	return 0;
}
