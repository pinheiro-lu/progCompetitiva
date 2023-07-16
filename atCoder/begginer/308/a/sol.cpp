#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n = 8;
	int s[n];
		for (int i = 0; i<n; i++){
		cin >> s[i];
	}

	for (int i = 0; i < 7; i++) {
		if (s[i] > s[i+1] || s[i] < 100 || s[i] > 675 || s[i] % 25) {
			cout << "No";
			return;
		}
	}
	cout << "Yes";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

