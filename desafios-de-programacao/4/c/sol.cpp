#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

void solve() {
	int n;
	cin >> n;
	for (int i = 2; i*i <= n; ++i) {
		if (n % i == 0) {
			cout << n / i << ' ' << n - n / i << '\n';
			return;
		}
	}
	cout << 1 << ' ' << n - 1 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt; cin >> tt;

	while (tt--) {
		solve();
	}


	return 0;
}
