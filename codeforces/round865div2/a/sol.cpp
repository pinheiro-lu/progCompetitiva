#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int a, b;

	cin >> a >> b;

//	if (!(a % b) || !(b % a)) {
		cout << "2\n" << a-1 << ' ' << "1\n" << a << ' ' << b << '\n';
//	} else {
//		cout << "1\n" << a << ' ' << b << '\n';
//	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}

