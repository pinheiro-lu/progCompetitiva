#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'
#define MOD 998244353

#define int long long

int wins[2][71];

int mod(int a, int m) {
	return a%m;
}

int modPow(int b, int p,int m) {
	if (p == 0) return 1;
	int ans = modPow(b,p/2, m);
	ans = mod(ans*ans, m);
	if (p & 1) ans = mod(ans * b, m);
//	cout << "b, p, modPow\n";
//	cout << b << ' ' << p << ' ' << ans << '\n';
	return ans;
}

int C(int n, int k) {
	int prod = 1;
	for (int i = k+1; i <=n; ++i) {
		prod *= i;
		prod %= MOD;
	}
	int den = 1;
	for (int i = 1; i <=n-k; ++i) {
		den *= i;
		den %= MOD;
	}

	cout << "n, k, prod, den, modPow, modDiv\n";
	cout << n << ' ' << k << ' ' << prod << ' ' << den << ' ' << modPow(den, MOD-2, MOD) <<  ' ' << (prod * modPow(den, MOD-2, MOD)) % MOD << '\n';
	cout << "div: " << prod/den << '\n';
	
	int inverse_den = modPow(den, MOD-2, MOD);
	
	return (prod * inverse_den) % MOD;
//	return (prod / den) % MOD;
}


void count (int n) {
	wins[0][2] = 0;
	wins[1][2] = 1;

	for (int i = 4; i <= n; i+=2) {
		wins[1][i] += C(i, i/2)/2;
		wins[0][i] += C(i-2, i/2);
		wins[0][i] %= MOD;
		wins[1][i] %= MOD;
		wins[0][i] += wins[1][i-2];
		wins[1][i] += wins[0][i-2];
		wins[0][i] %= MOD;
		wins[1][i] %= MOD;
	//	cout << wins[1][i] << ' ' << wins[0][i] << " 1\n";
	}
}


void solve(void) {
	int n;
	
	cin >> n;

	cout <<	wins[1][n] << ' ' << wins[0][n] << " 1\n";
}

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin >> t;

	count(60);
	
	while (t--)
		solve();
		
	return 0;
}
