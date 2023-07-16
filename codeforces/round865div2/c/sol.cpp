#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;

	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (a[n-2] <= a[n-1]) cout << "yes\n";
	else {



}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}

