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
		int n, x; cin >> n >> x;
		vi a(n);
		int bt = -1, lst = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 1) {
				lst = i;
				if (bt == -1) {
					bt = i;
				}
			}
		}
		cout << (lst-bt+1<=x ? "YES" : "NO") << '\n';
	}

	return 0;
}
