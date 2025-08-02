#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 10;

array<array<int, N>, N> grid;
int n, m;

int solve (int idx, int mask) {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (grid[idx][i] && !(mask & (1 << i))) {
			ans = max(ans, grid[idx][i] + solve(i, mask | (1 << i)));
		}
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		grid[a][b] = grid[b][a]=c;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, solve(i, 1 << i));
	}
	cout << ans << '\n';

	return 0;
}
