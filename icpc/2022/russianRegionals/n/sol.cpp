#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string x;
	int k;

	cin >> x >> k;
	int i = 0;	
	while (k--) {	
		if (x[i] >= x[i+1]) {
			x.erase(i, i+1);
		} else {
			x.erase(i+1, i+2);
		}
		cout << "ta " << x << '\n';
	}
	cout << x << '\n';	
}

int main() {
	int t;

	cin >> t;

	while (t--) solve();

	return 0;
}
