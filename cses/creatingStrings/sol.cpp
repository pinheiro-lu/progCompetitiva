#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string a[100000];

void solve() {
	string s;
	cin >> s;
	
	sort(s.begin(), s.end());

	int i = 0;

	do {
		a[i++] = s;
	} while (next_permutation(s.begin(), s.end()));

	cout << i << '\n';

	for (int j = 0; j < i; j++) {
		cout << a[j] << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
