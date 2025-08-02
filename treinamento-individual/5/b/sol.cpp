#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

ll MOD = 1e9 + 7;
multiset<int> s;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	ll ans = 0;
	for (auto it = s.begin(); it != s.end(); ) {
		int x = *it;
		int cnt = s.count(x);
		ans += cnt * (ans + 1);
		ans %= MOD;
		//cerr << ans << '\n';
		advance(it, cnt);
	}
	cout << ans << '\n';

	return 0;
}
