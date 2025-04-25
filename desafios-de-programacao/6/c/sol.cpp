#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e6+1;

array<int, N> dp;
int n;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	dp.fill(INT_MAX);
	dp.at(n) = 0;
	for (int i = n; i >= 0; --i) {
		if (dp.at(i) == INT_MAX) continue;
		set<int> dig;
		int x = i;
		while (x) {
			dig.insert(x % 10);
			x /= 10;
		}
		for (int d : dig) {
			if (d == 0) continue;
			int j = i - d;
			if (j < 0) continue;
			dp.at(j) = min(dp.at(j), dp.at(i) + 1);
		}
	}

	cout << dp.at(0) << '\n';

	return 0;
}
