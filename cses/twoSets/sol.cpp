#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll n; cin >> n;

	if (n % 4 == 1 || n % 4 == 2) cout << "NO\n";
	else {
		cout << "YES\n";
	//	if (n & 1) {
			ll sum = (ll) n*(n+1)/4;

			unordered_set<int> s, t;

			for (int i = n; i > 0; i--) {
				if (sum >= i) {
					s.insert(i);
					sum -= i;
				} else {
					t.insert(i);
				}
			}
			cout << s.size() << '\n';
			for (int x : s) {
				cout << x << ' ';
			}
			cout << '\n' << t.size() << '\n';
			for (int x : t) {
				cout << x << ' ';
			}
		/*} else {
			cout << n/2 << '\n';
			for (int i = 1; i <=n; i+=2) {
				cout << i << ' ';
			}
			cout << '\n' << n/2 << '\n';
			for (int i = 2; i <=n; i+=2) {
				cout << i << ' ';
			}
		}*/
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	//cin >> t;
	while (t--) solve();

	return 0;
}

