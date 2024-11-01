#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int d(int n) {
	int sum = 0;
	do {
		sum += n%10;
	} while (n/=10);
	return sum;
}

void solve() {
	int l, r, k;
	cin >> l >> r >> k;
	cout << l << ' ' << r << ' ' << k << '\n';;

	int sum = 0;
	for (int i = (int)pow(10,l); i < (int)pow(10, r); ++i) {
		cout << d(k*i) << ' ' << k*d(i) << '\n';
		if (i % 10 == 0) cout << '\n';
		/*if (d(k*i) == k*d(i)) {
			cout << i << ' ';
			if (i % 10 == 0) cout << '\n';
			++sum;
		}*/
	}
	cout << '\n' << sum << "\n\n";
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
