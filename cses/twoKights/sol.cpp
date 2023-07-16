#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, ans = 96;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i == 1) cout << "0\n";
		else if (i == 2) cout << "6\n";
		else if (i == 3) cout << "28\n";
		else if (i == 4) cout << "96\n";
		else {
			ans += i

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}

