#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n = 1;

	while (true) {
		cin >> n;
		if (!n) break;
		int x = n;
		bool aTurn = true;
		int a = 0, b = 0;

		while (x) {
			if (aTurn) {
				a = a | (x & -x);
			} else
				b |= (x & -x);
			aTurn = !aTurn;
			x -= x & -x;
		}
		cout << a << ' ' << b << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

