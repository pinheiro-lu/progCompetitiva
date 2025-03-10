#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

array<array<char, 250>, 250> grid;
array<array<bool, 250>, 250> vis;

int r, c;
int totv, totk;

pair<int, int> solve(int x, int y) {
	if (x >= r || y >= c || x < 0 || y < 0) return {0, 0};
	if (vis.at(x).at(y)) return {0, 0};
	vis.at(x).at(y) = true;
	if (grid.at(x).at(y) == '#') return {0, 0};
	auto [v, k] = solve(x+1, y);
    auto [v2, k2] = solve(x, y+1);
    auto [v3, k3] = solve(x-1, y);
    auto [v4, k4] = solve(x, y-1);
	v += v2 + v3 + v4; k += k2 + k3 + k4;
	if (grid.at(x).at(y) == 'v') return {v+1, k};
	if (grid.at(x).at(y) == 'k') return {v, k+1};
	return {v, k};
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> grid.at(i).at(j);
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (vis.at(i).at(j)) continue;
			auto [v, k] = solve (i, j);
			if (k > v) totk += k;
			else totv += v;
		}
	}

	cout << totk << ' ' << totv << '\n';

	return 0;
}
