#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	bool r, g, b;
	int tt;
	cin >> tt;
	while (tt--) {
		r = g = b = false;
		string s;
		cin >> s;
		bool open = true;
		for (char c : s) {
			if (c == 'r') r = true;
			if (c == 'g') g = true;
			if (c == 'b') b = true;
			if ((c == 'R' && !r) ||
					(c == 'G' && !g) ||
					(c == 'B' && !b)) {
				open = false;
			}
		}
		cout << (open ? "YES\n" : "NO\n");
	}

	return 0;
}
