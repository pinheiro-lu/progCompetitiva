#include <bits/stdc++.h>

using namespace std;

int n;
const int N = 1e6;

typedef long long ll;

array<ll, N+1> a, num_here, cnt, dist;
set <pair<int, int>> moo;
set <ll> all;
array<bool, N+1> forbid;

signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a.at(i);
		all.insert(a.at(i));
		dist.at(i) = all.size()-1;
	}

	for (int i = n-1; i >= 0; --i) {
		num_here.at(i) = ++cnt.at(a.at(i));
	}

	ll ans = 0;
	for (int i = n-1; i >= 0; --i) {
		if (forbid.at(a.at(i))) continue;
		if (num_here.at(i) > 1) {
			ans += dist.at(i);
			forbid.at(a.at(i)) = true;
		}
	}

	cout << ans << '\n';
	
	return 0;
}



