#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string s;

void solve() {
	cin >> n;

	cin >> s;

	int ans = 0;

	char certo = 'G', errado = 'H';

	for (int i = n-1; i >= 0; i-=2) {
		if (s[i] == errado && s[i-1] == certo) {
			++ans;
			char aux = certo;
			certo = errado;
			errado = aux;
		}
	}

	cout << ans << '\n';
	
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
