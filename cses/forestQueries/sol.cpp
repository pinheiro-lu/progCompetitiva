#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1000+1;

int n;
int q;

array<array<int, N>, N> grid;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char c;
			cin >> c;
			grid.at(i).at(j) = (c == '*') + grid.at(i-1).at(j) + grid.at(i).at(j-1) - grid.at(i-1).at(j-1);
		}
	}

	while (q--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << (grid.at(y2).at(x2) - grid.at(y2).at(x1-1) - grid.at(y1-1).at(x2) + grid.at(y1-1).at(x1-1)) << '\n';
	}

	return 0;
}
