#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	int b;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!i) {
			b = a[i];
		} else {
			b = b ^ a[i];
		}
	}
	if (n & 1){
		cout << b << '\n';
	} else {
		if (b == 0) {
			cout << "0\n";
		} else cout << "-1\n";
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}	

