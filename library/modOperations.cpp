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
