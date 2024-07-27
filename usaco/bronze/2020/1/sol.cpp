#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector <pair<int, int>> post;

void solve() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
	   int x, y;
	   cin >> x >> y;
	   post.push_back(make_pair(x, y));
	}
	int maxarea = 0;

	for (int i = 0; i < n; ++i) {
		int x = post[i].first;
		int y = post[i].second;
		for (int j = 0; j < n; ++j) {
			if (j == i) {
				continue;
			}
			int x1 = post[j].first;
			int y1 = post[j].second;
			if (x == x1) {
				for (int k = 0; k < n; ++k) {
					if (k == j || k == i) {
						continue;
					}
					int x2 = post[k].first;
					int y2 = post[k].second;
					if (y == y2) {
						int area = abs((x2 - x) * (y1 - y));
						maxarea = max(maxarea, area);
					}
				}
			}
		}
	}

	cout << maxarea << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);

	while (t--) solve();

	return 0;
}
