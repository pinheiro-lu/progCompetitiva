#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;

	vector <int> g;
	vector <int> l;

	for (int i = 0; i < n; ++i) {
		char c;
		int x;
		cin >> c >> x;
		if (c == 'L') l.push_back(x);
		else g.push_back(x);
	}

	int ans = n;

	for (int & x : g) {
		int lies = 0;
		for (int & y : g) {
			if (y > x) {
			   lies++;	
			}
		}
		for (int & y : l) {
			if (y < x) {
			   lies++;	
			}
		}
		ans = min(ans, lies);
	}

	for (int & x : l) {
		int lies = 0;
		for (int & y : g) {
			if (y > x) {
			   lies++;	
			}
		}
		for (int & y : l) {
			if (y < x) {
			   lies++;	
			}
		}
		ans = min(ans, lies);
	}

	cout << ans << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
