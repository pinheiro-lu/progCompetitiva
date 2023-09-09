#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int a, b, c;

	cin >> a >> b >> c;

	int qtd = abs(a-b)/2;
	if (abs(a-b) & 1) ++qtd;

	cout << ((qtd % c) ? qtd/c + 1 : qtd/c) << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
