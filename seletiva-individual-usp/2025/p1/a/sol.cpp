#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;

	while (tt--) {
		int n; cin >> n;
		string s; cin >> s;
		int vica = 0, vicb = 0;
		for (int x = 1; x <= n; ++x) {
			int wa = 0, wb = 0;
			int sa = 0, sb = 0;
			int i = 0;
			while (i < n) {
				while (i < n && wa < x && wb < x) {
					if (s[i] == 'A') {
						++wa;
					} else {
						++wb;
					}
					++i;
				}
				if (wa == x) {
					++sa;
					wa = wb = 0;
				} else if (wb == x) {
					++sb;
					wa = wb = 0;
				}
			}
			if (wa == 0 && wb == 0) {
				if (sa > sb && s[n-1] == 'A') ++vica;
				else if (sb > sa && s[n-1] == 'B') ++vicb;
			}
		}
		if (vica == 0 && vicb) {
			cout << "B\n";
		} else if (vicb == 0 && vica) {
			cout << "A\n";
		} else {
			//cerr << vica << ' ' << vicb << '\n';
			cout << "?\n";
		}
	}

	return 0;
}
