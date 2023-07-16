#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	string s;

	cin >> n >> s;

	int p = 0, g = 0;

	for (char c : s) {
		if (c == 'o') g++;
		else if (c == 'x') {
			cout << "No";
			return;
		}
	}
	if (g) cout << "Yes";
	else cout << "No";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

