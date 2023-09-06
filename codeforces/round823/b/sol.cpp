#include <bits/stdc++.h>

using namespace std;

#define MAX 100000000

typedef long long ll;

void solve (void) {
	int n;

	cin >> n;
	pair<ll, ll> x[n];

	for (int i = 0; i < n; ++i) {
		cin >> x[i].first;
		x[i].first*=2;
	}
	for (int i = 0; i < n; ++i) {
		cin >> x[i].second;
		x[i].second*=2;
	}
	ll l = 0, r = 2e8; 

	sort(x, x + n);
	for (int i = 0; i < n; ++i) {
		//cout << x[i].first << ' ' << x[i].second << '\n';
	}
	ll ans;

	while (l < r) {
		ans = (l + r) / 2;

		pair<ll, ll> mx, aux;
		mx = x[0];

		for (int i = 0; i < n; ++i) {
			aux = make_pair(x[i].first, x[i].second+abs(x[i].first-ans));
			if (aux.second > mx.second) mx = aux;
		}

		if (mx.first > ans) {
			l = ans + 1;
		} else if (mx.first < ans) {
			r = ans;
		} else break;
		cout << l << ' ' << mx.first << ' ' <<  ans << ' ' << r << '\n';
	}

	ans = (l + r) / 2;
	cout << ans/2;
	if (ans & 1) cout << ".5";
	cout << '\n';
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	
	cin >> T;
	
	while (T--)
		solve();
	
	return 0;
}
