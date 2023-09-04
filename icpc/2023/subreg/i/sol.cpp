#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

void solve() {
	int n; cin >> n;
	int b[n];

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = n-1; j>=i; --j) {
			int sum =0;
			for (int k = i; k <=j; ++k) {
				sum+=b[k];
			}
			if (sum & 1) ++ans;
		}
	}

	cout << ans;


	
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}
