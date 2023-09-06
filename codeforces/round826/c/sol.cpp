#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

void solve(void) {
	int n; cin >> n;

	int a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int ans = n;
	for (int len = 1; len <= n; ++len) {
		int sum = 0;
		for (int i = 0; i < len; ++i) {
			sum += a[i];
		}
		int sumAt = 0, maxSeg = len, seg = 0;
		int i;
		for (i = len; i < n; ++i) {
			sumAt += a[i];
//			cout << "sumAt: " << sumAt << '\n';
			++seg;
			if (sumAt > sum) break;
			if (sumAt == sum) {
//				cout << "seg: " << seg << '\n';
				sumAt = 0;
				maxSeg = max(maxSeg, seg);
				seg = 0;
			}
		}
		if (i == n && sumAt == 0) ans = min(ans, maxSeg);
	}

	cout << ans << '\n';
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}
