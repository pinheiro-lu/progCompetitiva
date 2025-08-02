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

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	BIT bit(n);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		bit.add(i, x);
	}

	while (q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) {
			bit.add(a, b-(bit.sum(a) - bit.sum(a-1)));
		} else {
			cout << bit.sum(b) - bit.sum(a-1) << '\n';
		}
	}

	return 0;
}
