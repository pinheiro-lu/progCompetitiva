#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string s;

void solve() {
	cin >> n;
	cin >> s;
	
	int tam;
	for (tam = 1; tam <= n; ++tam) {
		set<string> words;
		for (int i = 0; i < n-tam+1; ++i) {
			words.insert(s.substr(i, tam));
		}
		if (words.size() == n-tam+1) break;
	}

	cout << tam << '\n';


}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);

	while (t--) solve();

	return 0;
}
