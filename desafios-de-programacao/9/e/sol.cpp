#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1000;

array<array<char, N>, N> grid;
array<array<bool, N>, N> vis;
array<array<int, N>, N> dist;

array<array<int, 6>, 2> dx = {{
	{-1, 1, -1, 0, -1, 0},
	{-1, 1, 0, 1, 0, 1}
}};
array<array<int, 6>, 2> dy = {{
	{0, 0, 1, 1, -1, -1},
	{0, 0, 1, 1, -1, -1}
}};

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}
	priority_queue<pair<int, pair<int, int>>> pq;

	for (int i = 0; i < m; ++i) {
		dist[0][i] = grid[0][i] == '.';
		pq.push({-dist[0][i], {0, i}});
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dist[i][j] = INT_MAX;
		}
	}

	while (!pq.empty()) {
		auto [d, p] = pq.top();
		pq.pop();
		int y = p.f, x = p.s;
		if (vis[y][x]) continue;
		vis[y][x] = true;
		for (int i = 0; i < 6; ++i) {
			int ny = y + dy[y % 2][i];
			int nx = x + dx[y % 2][i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (vis[ny][nx]) continue;
			int nd = dist[y][x] + (grid[ny][nx] == '.');
			if (nd < dist[ny][nx]) {
				dist[ny][nx] = nd;
				pq.push({-nd, {ny, nx}});
			}
		}
	}

	int ans = INT_MAX;

	for (int i = 0; i < m; ++i) {
		ans = min(ans, dist[n - 1][i]);
	}

	cout << ans << '\n';

	return 0;
}
