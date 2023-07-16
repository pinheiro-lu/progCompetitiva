#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;

	cin >> n;

	vector<int> a(2*n);

	int maxp = 2*n, minp = 2, maxi = 2*n-1, mini = 1;

	for (int i = 0; i < n; i++) {
		if (~i & 1) {
			a[i] = maxp;
			maxp-=2;
		} else {
			a[i] = minp;
			minp+=2;
		}
	}

	for (int i = 2*n-1; i >= n; i--) {
		if (i & 1) {
			a[i] = maxi;
			maxi-=2;
		}
	}

	for (int i = n; i < 2*n; i++) {
		if (~i & 1) {
			a[i] = mini;
			mini+=2;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	for (int i = n; i < 2*n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}

