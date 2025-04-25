#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5 + 5;

array<int, N> memo;
array<int, N> h;
int n, k;

int dp (int i) {
	if (i == 0) return 0;
	if (memo[i] != -1) return memo[i];

	int ans = INT_MAX;
	for (int j = 1; j <= k; j++) {
		if (i - j >= 0) {
			ans = min(ans, dp(i - j) + abs(h[i] - h[i - j]));
		}
	}

	return memo[i] = ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memo.fill(-1);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	cout << dp(n-1) << '\n';

	return 0;
}
