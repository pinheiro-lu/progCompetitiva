#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, d;
	cin >> n >> d;
	string s;
	cin >> s;
	string ans;
	string aux;
	for (int i = 0; i <= n; i++) {
		aux = s;
		aux.insert(i, to_string(d)); 
		if (aux > ans) {
			ans = aux;
		}
	}
	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}	

