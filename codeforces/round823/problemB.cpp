#include <iostream>
#include <cstdio>
#include <algorithm>

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
	ll l = 0, r = 1e8; 

	sort(x, x + n);
	ll ans;

	while (l < r) {
		ans = (l + r) / 2;

		pair<ll, ll> mx, aux;
		mx = make_pair(0,0);

		for (int i = 0; i < n; ++i) {
			aux = make_pair(i, x[i].second+abs(x[i].first-ans));
			mx = max(mx, aux, [](const auto& l, const auto& r) {
				return l.second < r.second;
			});
		}

		if (x[mx.first].first > ans) {
			l = ans;
		} else if (x[mx.first].first < ans) {
			r = ans;
		} else break;
		cout << l << ' ' << r << '\n';
	}

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
