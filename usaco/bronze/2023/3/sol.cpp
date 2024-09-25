#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

int n, k;
vector<int> a;

void solve() {
	cin >> n >> k;
	a.resize(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int sum = k+1;

	for (int i = 1; i < n; ++i) {
		int d = a[i] - a[i-1];

		sum += min(k+1, d);
	}
		cout << sum << '\n';
	
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
