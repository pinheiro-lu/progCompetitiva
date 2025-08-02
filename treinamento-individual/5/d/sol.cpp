#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

// 1-indexed BIT (Fenwick Tree)
// add O(log n), sum O(log n)
// sum [1, k]
struct BIT {
	int n;
	vector<ll> bit;
	BIT(int n_) : n(n_) {
		bit.assign(n+1, 0);
	}
	ll sum(int k) const {
		ll s = 0;
		while (k >= 1) {
			s += bit[k];
			k -= k & -k;
		}
		return s;
	}
	void add(int k, ll x) {
		while (k <= n) {
			bit[k] += x;
			k += k & -k;
		}
	}
};

ll calc_wait(const BIT &going, int n, int m) {
	ll going_sum = going.sum(m);
	ll returning_sum = going.sum(n) - going.sum(m);
	return going_sum - returning_sum;
}

ll solve(const BIT &going, int n) {
	int l = 1, r = n;
	while (l < r-1) {
		int m = (l + r) / 2;
		ll wait = calc_wait(going, n, m);
		if (wait > 0)
			r = m;
		else
			l = m;
	}
	return min(abs(calc_wait(going, n, l)), abs(calc_wait(going, n, r)));
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	BIT going(n-1);
	for (int i = 0; i < n-1; ++i) {
		int x; cin >> x;
		going.add(i+1, x);
	}
	cout << solve(going, n-1) << '\n';

	int k;
	cin >> k;
	while (k--) {
		int i, x;
		cin >> i >> x;
		going.add(i, x-(going.sum(i) - going.sum(i-1)));
		cout << solve(going, n-1) << '\n';
	}

	return 0;
}
