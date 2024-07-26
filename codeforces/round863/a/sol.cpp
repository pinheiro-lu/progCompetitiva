#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, d;
	cin >> n >> d;
	string s;
	cin >> s;

	for (int i = 0; i < n; ++i) {
		if (s[i] < d + '0') {
			s.insert(i, 1, d + '0');
			break;
		}
	}
	if (s.length() == n) s.push_back(d + '0');

	cout << s << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}	

