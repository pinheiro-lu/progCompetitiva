#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

vi x;
int n, q;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	x.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> x.at(i);
	}

	sort(x.begin(), x.end());

	cin >> q;

	while (q--) {
		int m;
		cin >> m;
		int l = 0, r = n-1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (x.at(mid) <= m) {
				l = mid+1;
			} else {
				r = mid;
			}
			cerr << l << ' ' << r << '\n';
		}
		cout << l << '\n';
	}

	return 0;
}
