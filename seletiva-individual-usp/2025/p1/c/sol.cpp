#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 3e5;

array<array<ll, N>, 2> a;
array<array<ll, N>, 2> mem;
array<array<bool, N>, 2> vis;

array<int, 4> dx = {0, 1, 0, -1};
array<int, 4> dy = {1, 0, -1, 0};

ll dp(int i, int j, int v) {
	if (v == 2*n-1) return a[i][j] * v;
	if (mem[i][j]) return mem[i][j];
	ll ans = 0;
	for (int k = 0; k < 4; ++k) {
		int ni = i + dx[k];
		int nj = j + dy[k];
		if (ni < 0 || ni >= 2 || nj < 0 || nj >= n) continue;
		if (vis[ni][nj]) continue;
		vis[ni][nj] = true;
		ans = max(ans, dp(ni, nj, v+1));
		vis[ni][nj] = false;
	}
	if (ans == 0) return -LLONG_MAX;
	ans += v *a[i][j];
	return mem[i][j] = ans;
}
		

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	cerr << -LLONG_MAX << '\n';

	cout << dp(0,0,0) << '\n';

	return 0;
}
