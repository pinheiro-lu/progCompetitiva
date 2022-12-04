#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve () {
	ll n;

	cin >> n;

	ll a, b;
	
	if (~n & 1) {
		a = b = n/2;
	} else {
		for (int i = n/2; i >= 1; i--) {
			a = i; b = n-i;
			if (b % a == 0) break;
			a = 1; b = n-1;
		}
	}
	cout << a << ' ' << b << '\n';
}

int main() {
	int t;

	cin >> t;

	while (t--) solve();

	return 0;
}
