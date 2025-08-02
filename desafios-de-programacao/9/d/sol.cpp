#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1000;

int n, m;

array<array<char, N>, N> grid;
array<array<pair<int,int>, N>, N> par;
vector<pair<int, int>> monsters;
pair<int, int> start;

array<int, 4> dx = {1, -1, 0, 0};
array<int, 4> dy = {0, 0, 1, -1};
array<char, 4> dir = {'R', 'L', 'D', 'U'};

void print_path(int y, int x) {
	vector<char> path;
	while (y != start.f || x != start.s) {
		auto [py, px] = par[y][x];
		for (int i = 0; i < 4; ++i) {
			if (y == py + dy[i] && x == px + dx[i]) {
				path.push_back(dir[i]);
				break;
			}
		}
		y = py;
		x = px;
	}
	reverse(path.begin(), path.end());
	cout << path.size() << '\n';
	for (char c : path) {
		cout << c;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'M') {
				monsters.push_back({i, j});
			} else if (grid[i][j] == 'A') {
				start = {i, j};
			}
		}
	}

	queue<tuple<int, int, char>> q;
	for (auto [y, x] : monsters) {
		q.push({y, x, 'M'});
	}
	q.push({start.f, start.s, 'A'});

	while (!q.empty()) {
		auto [y, x, c] = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				if (c == 'A') {
					cout << "YES\n";
					print_path(y, x);
					return 0;
				} else continue;
			}
			if (grid[ny][nx] == '.') {
				grid[ny][nx] = c;
				par[ny][nx] = {y, x};
				q.push({ny, nx, c});
			}
		}
	}
	cout << "NO\n";

	return 0;
}
