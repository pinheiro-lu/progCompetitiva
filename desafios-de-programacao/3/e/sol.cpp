#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, x;
	cin >> n >> x;
	map<ll, int> cnt;
	cnt[0] = 1;
	ll sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		sum += a;
		ans += cnt[sum - x];
		cnt[sum]++;
	}
	cout << ans << '\n';

	return 0;
}
