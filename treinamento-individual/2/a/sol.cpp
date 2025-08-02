#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	set<string> s;
	for (int i = 0; i < 4; ++i) {
		string t; cin >> t;
		s.insert(t);
	}
	if (s.size() == 4) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
