#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll a;

	cin >> a;

	cout << a << '\n';

	while (a > 9) {
		a = a/10*3 + a%10;
		cout << a << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

