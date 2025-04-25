#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1001;
const int MOD = 1e9 + 7;

array<array<int, N>, N> dp;
array<array<char, N>, N> sq;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> sq[i][j];
		}
	}
	dp.at(h - 1).at(w - 1) = 1;
	for (int i = h - 1; i >= 0; --i) {
		for (int j = w - 1; j >= 0; --j) {
			if (sq[i][j] == '#') continue;
			if (i == h - 1 && j == w - 1) continue;
			dp.at(i).at(j) = (dp.at(i + 1).at(j) + dp.at(i).at(j + 1)) % MOD;
		}
	}
	cout << dp.at(0).at(0) << '\n';

	return 0;
}
