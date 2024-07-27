#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	char mn = s[0];
	int mni = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] <= mn) {
			mn = s[i];
			mni = i;
		}
	}

	s.erase(mni, 1);
	s.insert(0, 1, mn);

	cout << s << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}	

