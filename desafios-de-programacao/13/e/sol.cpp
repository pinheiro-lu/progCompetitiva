#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n;
const int N = 2e5;

array<int, N> h, a;
map<pair<int, int>, ll> mem;

ll dp(int i, int height) {
	if (i == n) {
		return 0;
	}

	if (mem.count({i, height})) {
		return mem[{i, height}];
	}

	ll ans = mem[{i, height}] = dp(i + 1, height);
	if (h[i] < height) {
		return ans;
	}

	return mem[{i, height}] = max(ans, a[i]+dp(i + 1, h[i]));
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i <n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i <n; i++) {
		cin >> a[i];
	}

	cout << dp(0, 0) << '\n';

	return 0;
}
