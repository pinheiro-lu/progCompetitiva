#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
char a[1005][1005];
vector<pair<int, int>> sum;

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sum.push_back({i, j});
		}
	}

	sort(sum.begin(), sum.end(), [&](auto a, auto b) {
		return a.first + a.second > b.first + b.second;
	});

	int ans = 0;

	for (auto [i, j] : sum) {
		if (a[i][j] == '1') {
			for (int x = 0; x <= i; ++x) {
				for (int y = 0; y <= j; ++y) {
					a[x][y] = a[x][y] == '1' ? '0' : '1';
				}
			}
			++ans;
		}
	}

	cout << ans << '\n';

	
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

	while (t--) solve();

	return 0;
}
