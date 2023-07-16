#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s;
	int x = 0;

	cin >> s;

	for (char c : s) {
		if (c == 'X') x++;
	}
	if (x != 2) cout << '?';
	else if(s[1] == 'O') cout << '*';
	else cout << "Alice";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

