#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const ll MOD = 1e9 + 7;

/* Retorna x^n % MOD */
ll mod_pow(ll x, int n, ll MOD = MOD) {
	if (n == 0) return 1;
	if (n == 1) return x;
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
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << mod_pow(a, (int)mod_pow(b, c, MOD-1)) << '\n';
	}

	return 0;
}
