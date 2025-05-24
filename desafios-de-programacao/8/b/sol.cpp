#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1000;

array<array<char, N>, N> grid;
array<array<bool, N>, N> vis;

int n, m;
int ans;

array<int, 4> dx = {0, 1, 0, -1};
array<int, 4> dy = {1, 0, -1, 0};

void dfs(int i, int j) {
	//cerr << i << ' ' << j << '\n';
	if (i == n || j == m || i < 0 || j < 0 || grid[i][j] == '#' || vis[i][j]) return;
	vis[i][j] = true;

	for (int k = 0; k < 4; ++k) {
		dfs(i + dx[k], j + dy[k]);
	}
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '.' && !vis[i][j]) {
				++ans;
				dfs(i, j);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
