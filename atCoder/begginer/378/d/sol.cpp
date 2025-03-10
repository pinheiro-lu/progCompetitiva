#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

#define MAXH 12
#define MAXW 12
#define MAXK 12

int h, w, k;
array<array<char, MAXW>, MAXH> mt;
array<array<array<int, MAXW>, MAXH>, MAXK> dp;

int solve(int c, int r, int n) {
	if (n == 0) return mt.at(r).at(c) == '.';
	if (mt.at(r).at(c) == '#') return 0;
	//if (dp.at(n).at(r).at(c) != -1) return dp.at(n).at(r).at(c);
	mt.at(r).at(c) = '#';
	dp.at(n).at(r).at(c) = solve(c-1, r, n-1) + solve(c+1, r, n-1) + solve(c, r-1, n-1) + solve(c, r+1, n-1);
	mt.at(r).at(c) = '.';
	return dp.at(n).at(r).at(c);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> h >> w >> k;

	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= h; ++j) {
			for (int l = 0; l <= w; ++l) {
				dp.at(i).at(j).at(l) = -1;
			}
		}
	}

	for (int i = 0; i <= h+1; ++i) fill(mt.at(i).begin(), mt.at(i).end(), '#');
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			cin >> mt.at(i).at(j);
		}
	}

	int ans = 0;

	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			if (mt.at(i).at(j) == '#') continue;
			ans += solve(j, i, k);
		}
	}
/*
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= h; ++j) {
			for (int l = 0; l <= w; ++l) {
				cout << dp.at(i).at(j).at(l) << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
*/
	cout << ans << '\n';
	return 0;
}
