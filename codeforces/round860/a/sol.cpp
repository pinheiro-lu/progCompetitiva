#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;

	cin >> n;
	int a[n], b[n];

	for (int i = 0; i < n; i++) {
	       cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
	       cin >> b[i];
	}

	int c[n], d[n];
	int maxC = 0, maxD = 0;

	for (int i = 0; i < n; i++) {
		c[i] = max(a[i], b[i]);
		d[i] = min(a[i], b[i]);
		maxC = max(maxC, c[i]);
		maxD = max(maxD, d[i]);
	}
	if (maxC == c[n-1] && maxD == d[n-1]) cout << "yes\n";
	else cout << "no\n"; 
}

int main() {
	int t;

	cin >> t;

	while (t--) solve();

	return 0;
}
