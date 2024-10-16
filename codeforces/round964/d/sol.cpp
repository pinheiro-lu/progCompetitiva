#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s, t;
	cin >> s >> t;
	
	int i = 0;
	for (char &c : s) {
		if (i == t.size()) {
			break;
		}
		if (c == t[i]) {
			i++;
		}
		if (c == '?') {
			c = t[i];
			i++;
		}
	}

	for (char &c : s) {
		if (c == '?') {
			c = 'a';
		}
	}

	if (i == t.size()) {
		cout << "YES\n";
		cout << s << '\n';
	} else {
		cout << "NO\n";
	}

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
