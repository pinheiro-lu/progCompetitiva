#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

struct BIT {
	vector<int> bit;
	void add(int k, int x) {
		while (k <= n) {
			bit.at(k) += x;
			k += k&-k;
		}
	}

	int sum(int k) {
		int s = 0;
		while (k >= 1) {
			s += bit.at(k);
			k -= k&-k;
		}
		return s;
	}

	BIT(int n) {
		bit.resize(n);
	}
};


void solve() {
	cin >> n;

	BIT bit(n+1);

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		int nv;
		cin >> nv;
		bit.add(n-nv+1, 1);
		ans += bit.sum(n-nv);
	}

	cout << ans << '\n';



}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
