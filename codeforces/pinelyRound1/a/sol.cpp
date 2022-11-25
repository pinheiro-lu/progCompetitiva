#include <bits/stdc++.h>

using namespace std;

void solve (void) {
	int n, a, b;

	cin >> n >> a >> b;
	
	if (a + b +2 <= n|| (a==b && a==n)) {
		cout << "Yes\n";
		return;
	}

	cout << "no\n";

}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;

	while (t--)
		solve();
	return 0;
}
