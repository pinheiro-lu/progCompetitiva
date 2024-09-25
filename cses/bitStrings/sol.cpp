#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll modpow(int x, int n) {
	if (n == 1) return x;
	ll ans = modpow(x, n/2);
	if (n & 1) {
		return ans * ans % MOD * x % MOD;
	}
	return ans * ans % MOD;
}

void solve() {
	int n; cin >> n;
	
	cout << (ll) (modpow(2, n));

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

