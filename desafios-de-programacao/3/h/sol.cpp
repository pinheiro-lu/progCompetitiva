#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

ll query(ll l, ll r) {
	cout << "xor " << l << " " << r << endl;
	ll x;
	cin >> x;
	if (x == -1) exit(0);
	return x;
}

set<ll> ans;

void solve(ll l, ll r) {
	while (l < r) {
		ll m = (l + r) / 2;
		ll x = query(l, m);
		if (!x) {
			l = m+1;
			continue;
		}
		ll y = query(m+1, r);
		if (y == 0) {
			r = m;
			continue;
		}
		ans.insert(x);
		ans.insert(y);
		break;
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		ans.clear();
		ll n; cin >> n;
		ll l = 1, r = n;
		ll x = query(l, r);
		if (x) {
			while (l < r) {
				ll m = (l + r) / 2;
				ll y = query(l, m);
				if (y == 0) {
					l = m+1;
					continue;
				}
				if (y == x) {
					r = m;
					continue;
				} 
				ll ans1 = query(y, y);
				if (!ans1) {
					ll z = query(m+1, r);
					solve(l,m);
				} else {
					solve(m+1,r);
				}
			}
		} else {
			int i = 60;
			while (i) {
				if ((1LL << i) > n) {
					i--;
					continue;
				}
				ll x = query(1, (1LL << i) - 1);
				if (x) {
					ans.insert(x);
					solve(1LL<<i, n);
					break;
				}
				i--;
			}
		}
		cout << "ans";
		for (ll x : ans) {
			cout << " " << x;
		}
		cout << endl;
	}

	return 0;
}
