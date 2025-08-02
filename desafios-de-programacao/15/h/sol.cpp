#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const ll MOD = 1e9 + 7;

/* Modular operations for competitive programming (KACTL style)
   Requires: const ll MOD; typedef long long ll; (provided in your general template)
   Returns x^n % MOD (n >= 0) */
ll mod_pow(ll x, int n) {
	if (n == 0) return 1;
	ll ans = mod_pow(x, n/2);
	ans = ans * ans % MOD;
	if (n & 1) ans = ans * x % MOD;
	return ans;
}

/* Returns x/y % MOD if MOD is prime and gcd(y, MOD) == 1 */
ll mod_div(ll a, ll b) {
	return a * mod_pow(b, MOD - 2) % MOD;
}
const int N = 1e6+1;
array<int, N> fact;
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = 1LL * fact[i-1] * i % MOD;
	}
	while (n--) {
		int a; int b;
		cin >> a >> b;
		cout << mod_div(fact[a], 1LL * fact[b] * fact[a - b] % MOD) << '\n';
	}

	return 0;
}
