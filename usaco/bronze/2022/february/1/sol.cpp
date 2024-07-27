#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

void solve() {
	cin >> n;

	vector<int> a(n);
	int sum  = 0;

	for (int & x : a) {
		cin >> x;
		sum += x;
	}

	int part = -1;
	int ans;
	int numparts = n+1;

	while (part < sum) {
		--numparts;
		while (sum % numparts) {
			--numparts;
		}
		part = sum / numparts;
		int sumhere = 0;
		int i;
		for (i = 0; i < n; ++i) {
			sumhere += a[i];
			if (sumhere > part) break;
			if (sumhere == part) {
				sumhere = 0;
				continue;
			}
		}
		if (sumhere == 0 && i == n) {
			ans = n - numparts;
			break;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
