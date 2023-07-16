#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int v;

	while (cin >> v) {
		int t;
		cin >> t;
		cout << t * v * 2 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

