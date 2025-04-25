#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n, x;

const int X = 1e6+1;
const int N = 100;
const int MOD = 1e9+7;

array<ll, X> dp;
array<int, N> c;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	dp.at(0) = 1;

	for (int i = 1; i <= x; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i - c[j] >= 0) {
				dp.at(i) += dp.at(i - c[j]);
				dp.at(i) %= MOD;
			}
		}
	}
	cout << dp.at(x) << '\n';

	return 0;
}
