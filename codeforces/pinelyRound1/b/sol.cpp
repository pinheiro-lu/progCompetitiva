#include <bits/stdc++.h>

using namespace std;

void solve (void) {
	int n, ans = 0;

	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		if (a[i-1] != a[(i+1)%n]) {
			a.erase(a.begin() + i);
			++ans;
			--n;
			i = 0;
		}
	}
	if (n == 2) ans += 2;
	else if (n == 1) ++ans;
	else {
		ans += n/2 + 1;
	}

	cout << ans << '\n';
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;

	while (t--)
		solve();
	return 0;
}
