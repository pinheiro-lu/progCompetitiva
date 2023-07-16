#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int search(ll x, vector<ll>a, int n) {
	int l = 0, r = n-1, ans = -1;

	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] <= x) {
			ans = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return ans;
}

void solve(void) {
	int n, q;

	cin >> n >> q;
	
	vector<ll> a(n), h(n);
	cin >> a[0];
	h[0] = a[0];
	for (int i = 1; i < n; i++) {
		ll x;
		cin >> x;
		a[i] = max(a[i-1], x);
		h[i] = h[i-1] + x;
	}

	for (int i = 0; i < q; i++) {
		ll x;
		cin >> x;
		int ans;
		cout << ((ans = search(x, a, n)) == - 1 ? 0 : h[ans]) << ' ';
	}
	cout << '\n';

}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	
	cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}
