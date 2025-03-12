#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int r, c, k;
vector<vector<int>> seat;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> r;
	while (r) {
		cin >> c >> k;
		seat.assign(r+1, vector<int>(c+1));
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				char x; cin >> x;
				seat.at(i).at(j) = x == '.';
				seat.at(i).at(j) += seat.at(i).at(j-1);
				seat.at(i).at(j) += seat.at(i-1).at(j);
				seat.at(i).at(j) -= seat.at(i-1).at(j-1);
			}
		}

		/*
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				cerr << seat.at(i).at(j) << ' ';
			}
			cerr << '\n';
		}
		*/

		int ans = c * r;
		for (int lr = 1; lr <= r; ++lr) {
			for (int rr = lr; rr <= r; ++rr) {
				for (int lc = 1, rc = 1; lc <= c, rc <= c;) {
					int sum = seat.at(rr).at(rc) - seat.at(rr).at(lc-1) - seat.at(lr-1).at(rc) + seat.at(lr-1).at(lc-1);
					if (sum >= k) {
						ans = min(ans, (rc-lc+1) * (rr-lr+1));
						++lc;
					} else {
						++rc;
					}
				}
			}
		}
		cout << ans << '\n';
		cin >> r;
	}
	return 0;
}

