#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcdv[1010][1010];
int nums[1010];

void precalc() {
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			gcdv[i][j] = gcd(i, j);
		}
	}
}

bool isPrime(int i, int j) {
	return gcdv[i][j] == 1;
}

void solve() {
	int n; cin >> n;
	memset(nums, 0, sizeof nums);

	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;

		nums[x] = i;
	}
	int ans = -1;

	for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			if (nums[i] && nums[j] && isPrime(i, j)) {
				ans = max(ans, nums[i] + nums[j]);
			}
		}
	}

	cout << ans << '\n';
			

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	precalc();
	while (t--) solve();

	return 0;
}
