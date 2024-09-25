#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

void solve() {
	map<string, int> mp;
	mp.insert(make_pair("Bessie", 0));
	mp.insert(make_pair("Elsie", 0));
	mp.insert(make_pair("Daisy", 0));
	mp.insert(make_pair("Gertie", 0));
	mp.insert(make_pair("Annabelle", 0));
	mp.insert(make_pair("Maggie", 0));
	mp.insert(make_pair("Henrietta", 0));

	cin >> n;
	
	while (n--) {
		string s;
		int x;

		cin >> s >> x;

		mp[s] += x;
	}

	multimap<int, string> mmp;

	for ( auto &[s, x] : mp ) {
		mmp.insert(make_pair(x, s));
	}

	auto it = mmp.upper_bound(mmp.begin()->first);

	if (it == mmp.end() || mmp.count(it->first) > 1) {
		cout << "Tie\n";
	} else {
		cout << it->second << '\n';
	}

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);

	while (t--) solve();

	return 0;
}
