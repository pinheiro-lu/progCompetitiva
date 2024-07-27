#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
char a[1010], b[1010];

void solve() {
	cin >> n >> a >> b;

	bool changing = false;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i]) {
			changing = false;
		} else {
			if (!changing) {
				++ans;
				changing = true;
			}
		}
	}

	cout << ans << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);

	while (t--) solve();

	return 0;
}
