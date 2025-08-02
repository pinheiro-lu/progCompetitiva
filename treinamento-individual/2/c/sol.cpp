#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 500;

array<array<int, N>, N> a, b;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;

	bool ok = true;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		int sum_a = 0, sum_b = 0;
		for (int j = 0; j < m; ++j) {
			sum_a += a[i][j];
			sum_b += b[i][j];
		}
		if (sum_a % 2 != sum_b % 2) {
			ok = false;
			break;
		}
	}
	for (int j = 0; j < m; ++j) {
		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < n; ++i) {
			sum_a += a[i][j];
			sum_b += b[i][j];
		}
		if (sum_a % 2 != sum_b % 2) {
			ok = false;
			break;
		}
	}
	cout << (ok ? "Yes\n" : "No\n");

	return 0;
}
