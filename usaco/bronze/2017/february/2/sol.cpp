#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s; cin >> s;
	int sum = 0;

	for (int i = 0; i < 52; ++i) {
		bool let[26]{};
		int j;
		for (j = i+1; j < 52 && s[j] != s[i]; ++j) {
			let[s[j]-'A'] = !let[s[j]-'A'];
		}
		if (j != 52)
		for (int i = 0; i < 26; ++i) {
			sum += let[i];
		}
	}

	cout << sum / 2 << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	while (t--) solve();

	return 0;
}
