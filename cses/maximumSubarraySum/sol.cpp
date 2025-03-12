#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll sum = 0;
	cin >> n;

	ll ans = -1e9;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		sum += x;
		ans = max(ans, sum);
		if (sum < 0) sum = 0;
	}

	cout << ans << '\n';

	return 0;
}
