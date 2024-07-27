#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string count (ll k) {
	string ans;
	while (k) {
		ans.insert(0, 1, k % 9 + '0');
		k /=9;
	}
//	cout << "ans: " << ans << '\n';
	return ans;

}

void solve() {
	ll k; cin >> k;
	string ans = count(k);

	for (int i = 0; i < ans.length(); ++i) 
		if (ans[i] >= '4') ++ans[i];
	
	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
