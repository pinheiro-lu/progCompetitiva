#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int r, c, k;
vector<vector<char>> seat;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> r;
	while (r) {
		cin >> c >> k;
		seat.assign(r+1, vector<char>(c+1));
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= c; ++j) {
				cin >> seat.at(i).at(j);
				seat.at(i).at(j) += seat.at(i).at(j-1);
			}
		}

		int ans = r * c;
		for (int left = 1; left <= c; ++left) {
			for (int right = left; right <= c; ++right) {



		cin >> r;

	return 0;
}
