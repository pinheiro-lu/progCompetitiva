#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second
		
int n, m;
vi a, b;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		cin >> n >> m;
		a.resize(n);
		b.resize(m);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(b.begin(), b.end());
		a.at(0) = min(a.at(0), b.at(0)-a.at(0));
		bool ans = true;
		for (int i = 1; i < n; i++) {
			int idx = lower_bound(b.begin(), b.end(), a.at(i-1)+a.at(i))-b.begin();
			if (idx == m) {
				if (a.at(i-1) > a.at(i)) {
					ans = false;
					break;
				}
				continue;
			}
			if (a.at(i-1) <= a.at(i)) {
				a.at(i) = min(a.at(i), b.at(idx)-a.at(i));
			} else {
				a.at(i) = b.at(idx)-a.at(i);
			}
		}
		if (ans) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}


	return 0;
}
