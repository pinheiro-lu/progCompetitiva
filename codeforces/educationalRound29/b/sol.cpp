#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;

	vector <int>a(2*n);

	for (int & x : a) {
		cin >> x;
	}

	sort(a.begin(), a.end());

	set <int>ex;
	int ans = 1000000;

	for (int i = 0; i < 2*n-1; ++i) {
		ex.insert(i);

		for (int j = i+1; j < 2*n; ++j) {
			ex.insert(j);

			int sum = 0;
			for (int k = 0; k < 2*n-1; ++k) {
				while (ex.count(k)) ++k;
				int val1;
				if (k < 2*n)
				val1 = a[k++];
				else continue;
				while (ex.count(k)) ++k;
				int val2 = a[k];
				sum += val2-val1;
			}
			ans = min(ans, sum);
			ex.erase(j);
		}
		ex.clear();
	}

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
