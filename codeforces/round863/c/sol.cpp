#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> b(n-1);
	vector<int> a(n);

	for (int i = 0; i < n-1; i++) {
		cin >> b[i];
	}
	a[0] = b[0];
	for (int i = 1; i < n - 1; i++) {
		if (b[i] > b[i-1]) {
			a[i] = b[i-1];
		} else {
			a[i] = b[i];
		}
	}
	a[n-1] = b[n-2];
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}	

