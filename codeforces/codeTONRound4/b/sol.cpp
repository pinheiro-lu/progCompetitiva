#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;

	cin >> n;

	vector <int> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}


	for (int i = 1; i <= n; i++) {
		if (a[i] <= i) {
			cout << "yes\n";
			return;
		}
	}

	cout << "no\n";
}	

int main() {
	int t;

	cin >> t;

	while (t--) solve();

	return 0;
}
