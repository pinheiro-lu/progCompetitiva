#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	ll n, k;

	cin >> n >> k;
	
	if (n & 1) {
		if (k & 1) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	} else {
		cout << "yes\n";
	}
}

int main() {
	int t;

	cin >> t;
	while (t--) solve();

	return 0;
}
