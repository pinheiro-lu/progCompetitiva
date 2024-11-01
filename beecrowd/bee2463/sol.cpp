#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;

	int sum = 0;
	int best = 0;
	while (n--) {
		int x; 
		cin >> x;
		sum = max(0, sum + x);
		best = max(best, sum);
	}

	cout << best << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
