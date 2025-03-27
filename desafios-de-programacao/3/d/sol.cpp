#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 2e5 + 5;
array<int, N> k;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n; ++i) {
		cin >> k[i];
	}

	ll l = 0, r = 1e18;
	while (l < r) {
		ll m = (l + r) / 2;
		ll sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += m / k[i];
			if (sum >= t) {
				break;
			}
		}
		if (sum >= t) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	cout << l << '\n';

	return 0;
}
