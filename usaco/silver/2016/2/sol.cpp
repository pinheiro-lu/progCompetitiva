#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int x[1000], y[1000];

void solve() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; ++i) {
		int a = x[i] + 1;

		for (int j = 0; j < n; ++j) {
			int b = y[j] + 1;




}

signed main() {
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
