#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

void solve() {
	cin >> n;

	vector<string> s{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

	vector<pair<string, string>> v;

	for (int i = 0; i < n; ++i) {
		string a, b, x;
		cin >> a >> x >> x >> x >> x >> b;
		v.push_back({a, b});
	}
	sort(s.begin(), s.end());
	while (next_permutation(s.begin(), s.end())){
		bool permitido = true;
		for (auto[a, b] : v) {
			if (abs(find(s.begin(), s.end(), a) - find(s.begin(), s.end(), b)) != 1) {
				permitido = false;
			}
		}
		if (!permitido) continue;
		break;
	} 
	for (string &x : s) {
		cout << x << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

	while (t--) solve();

	return 0;
}
