#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n, m;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		sum += (ll) (x%m + m) * n;
	}
	cerr << sum << '\n';

	cout << sum % ((n+1)*n/2*m) << '\n';

	return 0;
}
