#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> a;
ll sum;
ll min_diff = LLONG_MAX;

void solve() {
	cin >> n;
	a.resize(n);

	for (ll &x : a) {
		cin >> x;
		sum += x;
	}

	do {
		for (int tam = 1; tam < n; ++tam) {
			ll cur = 0;
			for (int i = 0; i < tam; ++i) {
				cur += a[i];
			}
			min_diff = min(min_diff, abs(cur - (sum - cur)));
		}
	} while (next_permutation(a.begin(), a.end()));
				

	cout << min_diff << '\n';


}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
