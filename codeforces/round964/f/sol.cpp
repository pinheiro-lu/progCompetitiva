#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

vector<ll> fact(2e5+1);

ll mod_pow(ll x, int n) {
	if (n == 1) return x;
	ll ans = mod_pow(x, n/2);
	if (n & 1) {
		return ans * ans % MOD * x % MOD;
	}
	return ans * ans % MOD;
}

ll mod_div(ll a, ll b) {
	return  a * mod_pow(b, MOD-2) % MOD;
}

ll comb(int n, int k) {
	return mod_div(fact[n],fact[k]*fact[n-k] % MOD);
}

void solve() {
	int k, n;
	cin >> n >> k;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
	}

	ll ans = 0;
	for (int i = k/2; i < sum && n-(i+1) >= k/2; ++i) {
		ans += comb(i, k/2) * comb(n-(i+1), k/2);
		//cerr << "ans " << ans << endl;
		ans %= MOD;
	}

	cout << ans << endl;

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	fact[0]=1;
	for (int i = 1; i <= 2e5; ++i) {
		fact[i] = fact[i-1] * i % MOD;
	}

	cin >> t;
	while (t--) solve();

	return 0;
}
