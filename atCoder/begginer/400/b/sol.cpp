
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	ll x = 0;
	for (int i = 0; i <= m; ++i) {
		ll aux = 1;
		for (int j = 0; j < i; ++j) {
			aux *= n;
			if (aux > (ll)1e9) {
				cout << "inf\n";
				return 0;
			}
		}
		x += aux;
		if (x >(ll) 1e9) {
			cout << "inf\n";
			return 0;
		}
	}
	cout << x << '\n';

	return 0;
}
