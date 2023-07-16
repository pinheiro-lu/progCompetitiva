#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, t;
	cin >> n >> t;
	vector<int>a(n), b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]+=i;
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int ans = -2, mel = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] <= t && b[i] > mel) {
			mel = b[i];
			ans = i;
		}
	}

	cout << ans + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}

