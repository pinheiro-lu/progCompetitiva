#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	int alfa[26]{};

	for (int i = 0; i< n; ++i) {
		int alfa1[26]{}, alfa2[26]{};
		string s, r;
		cin >> s >> r;
		for (char c : s) {
			alfa1[c-'a']++;
		}
		for (char c : r) {
			alfa2[c-'a']++;
		}
		for (int i = 0; i < 26; ++i) {
			alfa[i] += max(alfa1[i], alfa2[i]);
		}
	}

	for (int i = 0; i < 26; ++i) {
		cout << alfa[i] << '\n';
	}
		
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

	while (t--) solve();

	return 0;
}
