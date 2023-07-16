#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n; cin >> n;
	ll x = 2*n+1; 
	cout << (26 + (11+x)*(n-4)/2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}

