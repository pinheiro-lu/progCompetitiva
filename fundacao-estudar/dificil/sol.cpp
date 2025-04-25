#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	assert(n >= 1 && n <= 5000);
	ll aba = 6, abc = 6;
	for (int i = 1; i < n; i++) {
		ll aux = aba;
		aba = (aba * 3 + 2 * abc) % MOD;
		abc = (aux * 2 + 2 * abc) % MOD;
	}

	cout << (aba + abc) % MOD << '\n';

	return 0;
}
