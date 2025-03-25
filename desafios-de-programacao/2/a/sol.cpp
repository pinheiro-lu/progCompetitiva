#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int m, a, b, c;
		cin >> m >> a >> b >> c;
		int ans = min(m,a) + min(m, b);
		int v = max(0, m-a) + max(0, m-b);
		ans += min(c,v);
		cout << ans << '\n';
	}
	return 0;
}
