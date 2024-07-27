#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, T;

void solve() {
	cin >> N >> T;

	string s;

	cin >> s;

	vector<tuple<int, int, int>> hooves(T);

	for (int i = 0; i < T; ++i) {
		int t, x, y;
		cin >> t >> x >> y;
		--x, --y;
		hooves[i] = make_tuple(t, x, y);
	}
 
	sort(hooves.begin(), hooves.end());

	set<int> posb;
	int smallest = 3000, largest = 0;

	for (int i = 0; i < N; ++i) {
		for (int k = 0; k <= 251; ++k) {
			vector <pair<bool, int>> infected(N);
			infected[i] = make_pair(true, k);
			for (int t = 0; t < T; ++t) {
				bool active = true;
				int cow = get<1>(hooves[t]);
				int cow2 = get<2>(hooves[t]);
				if (infected[cow].first && infected[cow].second > 0 ) {
					if (!infected[cow2].first) {
						infected[cow2].first = true;
						infected[cow2].second = k;
						active = false;
					}
					infected[cow].second--;
				}
				if (active && infected[cow2].first && infected[cow2].second > 0 ) {
					if (!infected[cow].first) {
						infected[cow].first = true;
						infected[cow].second = k;
					}
					infected[cow2].second--;
				}
			}
			string created("");
			for (int j = 0; j < N; ++j) {
				if (infected[j].first) {
					created.push_back('1');
				} else {
					created.push_back('0');
				}
			}
//			cout << created << '\n';
			if (s == created) {
				smallest = min(smallest, k);
				largest = max(largest, k);
				posb.insert(i);
			}
		}
	}
	cout << posb.size() << ' ' << smallest << ' ' << (largest == 251 ? "Infinity" : to_string(largest)) << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);

	while (t--) solve();

	return 0;
}
