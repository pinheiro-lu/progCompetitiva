#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

#define int long long

const int N = 3e5+1, MOD = 998244353;

array<pair<int, bool>, 2*N> aux;
array<vector<bool>, 2*N> actions;
array<int, N> fac;

/* Retorna x^n % MOD */
ll mod_pow(ll x, int n, ll MOD = MOD) {
	if (n == 0) return 1;
	ll ans = mod_pow(x, n/2, MOD);
	if (n & 1) {
		return ans * ans % MOD * x % MOD;
	}
	return ans * ans % MOD;
}

/* Retorna x/y % MOD se MOD for primo e coprimo de x*/
ll mod_div(ll a, ll b) {
	return  a * mod_pow(b, MOD-2) % MOD;
}

int n, k;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		aux[2*i] = {x, false}; 	 // on
		aux[2*i+1] = {y, true};  // off
	}

	sort(aux.begin(), aux.begin() + 2*n);

	for (int i = 0; i < 2*n; i++) {
		actions[lower_bound(aux.begin(), aux.begin() + 2*n, make_pair(aux[i].f, false)) - aux.begin()].push_back(aux[i].s);
	}
	int ans = 0;
	int active = 0;

	for (int i = 0; i < 2*n; i++) {
		for (bool action : actions[i]) {
			if (action) {
				active--;
			} else {
				active++;
				if (active < k) continue;
				ans += mod_div(fac[active-1], fac[active-1-(k-1)] * fac[k-1] % MOD);
				ans %= MOD;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
