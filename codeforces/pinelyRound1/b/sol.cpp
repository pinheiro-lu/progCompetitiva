#include <bits/stdc++.h>

using namespace std;

void solve (void) {
	int n, ans = 0;

	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	while (n > 1) {
t:
		bool ok = true;
		while (ok) {
			ok = false;
			for (int i = 0; i < n; i++) {
				if (a[i] == a[(i+1)%n]) {
					a.erase(a.begin()+i);
					n--;
					ok = true;	
				}
			}
		}
		int i;
		int j = 2;
		while (j < n) {
		for (i = 0; i < n; i++) {
			if (a[i] == a[(i+j)%n]) {
				a.erase(a.begin()+i);
				n--;
				ans++;
				goto t;
			}
		}
		if (i == n) {
			j++;
		}
		}
		n--;
		a.erase(a.begin());
		ans++;
	}

	cout << ans + 1 << '\n';
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
