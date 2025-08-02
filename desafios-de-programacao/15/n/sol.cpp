
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 2e5;

vi diff;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n; cin >> n;
		int ant; cin >> ant;
		diff.clear();
		for (int i = 1; i < n; ++i) {
			int x;
			cin >> x;
			if (x != ant) diff.push_back(i);
			ant = x;
		}
		int q; cin >> q;
		while (q--) {
			int l, r; cin >> l >> r;
			auto it = lower_bound(diff.begin(), diff.end(), l);
			int x;
			if (it == diff.end()) x = r;
			else x = *it;
			if (x < r) {
				cout << x << ' ' << x + 1 << '\n';
			} else {
				cout << "-1 -1\n";
			}
		}
		cout << '\n';
	}
			

	return 0;
}
