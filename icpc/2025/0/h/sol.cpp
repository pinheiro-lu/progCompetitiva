#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x; cin >> x;
	cerr << bitset<64>(x) << '\n';
	int l = 63-__builtin_clzll(x);
    int	r = (l+1)/2;
	ll ans = 0;
	if (x == 1) {
		cout << 1;
		return 0;
	}
	if ((x & (x-1)) == 0) { // x is a power of 2
		cout << x-1 << '\n';
		return 0;
	}
	for (int i = 0; i <= r; ++i) {
		ll aux = ans | (1LL << i) | (1LL << (l-i));
		if (aux <= x) {
			ans = aux;
		}
	}
	cout << ans << '\n';

	return 0;
}
