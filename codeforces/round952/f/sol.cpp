#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll h;
int n;

map<int, ll> mp;
vector<int> c;
vector<ll> a;

ll bs(ll l, ll r) {
	if (l == r) return l;
	ll x = (l + r)/2;
	ll sum = 0;
	for (auto &[i, dmg] : mp) {
		sum += x/i * dmg;
	}
	if (sum >= h) return bs(l, x);
	return bs(x+1, r);
}

void solve() {
	cin >> h >> n;

	a.resize(n);
	c.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> a.at(i);
		h-=a.at(i);
	}

	for (int i = 0; i < n; ++i) {
		cin >> c.at(i);
		if (mp.count(c.at(i))) {
			mp.insert_or_assign(c.at(i), mp.at(c.at(i))+a.at(i));
		} else {
			mp.insert({c.at(i), a.at(i)});
		}
	}

	if (h <= 0) {
		cout << "1\n";
	} else {
		cout << 1 + bs(1, 4e10) << '\n';
	}
	mp.clear();

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
