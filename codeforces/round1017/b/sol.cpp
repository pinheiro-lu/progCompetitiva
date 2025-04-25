
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
		int n, m, l, r;
		cin >> n >> m >> l >> r;
		int lans = 0, rans = 0;
		while (lans > l && (rans - lans) < m) {
			lans--;
		}
		while (rans < r && (rans - lans) < m) {
			rans++;
		}
		cout << lans << " " << rans << '\n';
	}

	return 0;
}
