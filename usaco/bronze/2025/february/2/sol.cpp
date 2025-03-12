#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+1;

array<int, N> a, mstinc;

signed main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		a.at(x)++;
	}

	for (int i = 1; i <= n; ++i) {
		mstinc.at(i) = mstinc.at(i-1) + (a.at(i-1) == 0);
	}

	for (int x = 0; x <= n; ++x) {
		cout << max(mstinc.at(x), a.at(x)) << '\n';
	}

	return 0;
}



