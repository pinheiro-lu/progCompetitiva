#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n, k;

#define N 8

array<array<int, N>, N> grid;
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; ++i) {
			for (int j = x1; j < x2; ++j) {
				grid.at(i).at(j)++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			ans += grid.at(i).at(j) == k;
		}
	}

	for (int yl = 0; yl < N; ++yl) {
		for (int yr = yl; yr < N; ++yr) {
			for (int xl = 0; xl < N; ++xl) {
				for (int xr = xl; xr < N; ++xr) {
					for (int i = yl; i <= yr; ++i) {
						for (int j = xl; j <= xr; ++j) {
							grid.at(i).at(j)++;
						}
					}
					int sum = 0;
					for (int i = 0; i < N; ++i) {
						for (int j = 0; j < N; ++j) {
							sum += grid.at(i).at(j) == k;
						}
					}
					ans = max(ans, sum);
					for (int i = yl; i <= yr; ++i) {
						for (int j = xl; j <= xr; ++j) {
							grid.at(i).at(j)--;
						}
					}
				}
			}
		}
	}


	for (int yl = 0; yl < N; ++yl) {
		for (int yr = yl; yr < N; ++yr) {
			for (int xl = 0; xl < N; ++xl) {
				for (int xr = xl; xr < N; ++xr) {
					for (int i = yl; i <= yr; ++i) {
						for (int j = xl; j <= xr; ++j) {
							grid.at(i).at(j)++;
						}
					}
					for (int y2l = 0; y2l < N; ++y2l) {
						for (int y2r = y2l; y2r < N; ++y2r) {
							for (int x2l = 0; x2l < N; ++x2l) {
								for (int x2r = x2l; x2r < N; ++x2r) {
									if (x2l > xr || x2r < xl || y2l > yr || y2r < yl) {
										int sum = 0;
										for (int i = y2l; i <= y2r; ++i) {
											for (int j = x2l; j <= x2r; ++j) {
												grid.at(i).at(j)++;
											}
										}
										for (int i = 0; i < N; ++i) {
											for (int j = 0; j < N; ++j) {
												sum += grid.at(i).at(j) == k;
											}
										}
										ans = max(ans, sum);
										for (int i = y2l; i <= y2r; ++i) {
											for (int j = x2l; j <= x2r; ++j) {
												grid.at(i).at(j)--;
											}
										}
									}
								}
							}
						}
					}
					for (int i = yl; i <= yr; ++i) {
						for (int j = xl; j <= xr; ++j) {
							grid.at(i).at(j)--;
						}
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
