
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		string s, p;
		cin >> p >> s;
		int n = s.size(), m = p.size();
		int cp = 0, cs = 0;
		int p1 = 0, p2 = 0;
		for (int i = 1; i < m; i++) {
			while (p.at(i) == p.at(i-1)) ++cp;
			while (s.at(p2) == s.at(p2-1)) {
				++cs, ++p2;
			}




	return 0;
}
