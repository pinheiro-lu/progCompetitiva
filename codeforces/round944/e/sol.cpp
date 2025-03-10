#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;


#define f first
#define s second

#define int long long

int tt;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> tt;
	while (tt--) {
		int n, k, q;
		cin >> n >> k >> q;
		vi a(k+1);
		vi b(k+1);
		for (int i = 1; i <= k; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= k; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < q; ++i) {
			int d;
			cin >> d;
			int l = 0, r = k;
			while (l < r) {
				int m = (l+r)/2;
			//	cerr << m << '\n';
				if (a.at(m) > d) {
					r = m-1;
				} else {
					l = m+1;
				}
			}
			if (a.at(l) > d) {
				--l;
			}
			if (a.at(l) == d) {
				cout << b.at(l) << ' ';
			} else {
				int ans = ((b.at(l+1)-b.at(l))*(d-a.at(l)))/(a.at(l+1)-a.at(l)) + b.at(l);
				cout << ans << ' ';
			}
		}
		cout << '\n';
	}



	return 0;
}
