#include <bits/stdc++.h>
using namespace std;

void solve () {
		int n;
		string s;

		cin >> n;
		cin >> s;

		if (n % 3 == 2) {
			cout << "NO\n";
		       return;	
		}

		for (int i = 0; i < s.length()-1; i++) {
			if ((i+1) % 3 == 2) {
				if (s[i] != s[i+1]) {
					cout << "NO\n";
					return;
				}
			}
		}
		cout <<"YES\n";
	
}
int main () {
	int tt;

	cin >> tt;

	while (tt--) solve();

	return 0;
}
