#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;

	cin >> n;

	int par = 0, impar = 0;

	for (int i = 0 ; i < n; ++i) {
		int x;
		cin >> x;
		if (x % 2) {
			++impar;
		} else {
			++par;
		}
	}

	int ans = 0;

	while (par or impar) {
		if (par) {
			--par;
			++ans;
		} else {
			if (impar >= 2) {
				impar -= 2;
				++ans;
			} else {
				break;
			}
		}

		if (impar) {
			--impar;
			++ans;
		} else {
			break;
		}
	}
	if (impar) --ans;

	cout << ans << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
