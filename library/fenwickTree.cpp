// 1-indexed BIT
// add O(log n), sum O(log n)
// sum [1, k]
struct BIT {
	vector<ll> bit;
	BIT(int n = 1e5) {
		bit.assign(n+1, 0);
	}
	ll sum(int k) {
		ll s = 0;
		while (k >= 1) {
			s += bit.at(k);
			k -= k & -k;
		}
		return s;
	}
	void add(int k, ll x) {
		while (k <= n) {
			bit.at(k) += x;
			k += k&-k;
		}
	}
};
