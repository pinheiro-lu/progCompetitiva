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
		string s;
		cin >> s;
		s += s;
		int n = s.size();
		int l = 0, r = 0;
		int blue = 0, red = 0;
		if (s[r] == 'B') {
			blue++;
		} else {
			red++;
		}
		while (r-l < n/2-1 && r < n) {
			//cerr << "l: " << l << ", r: " << r << ", blue: " << blue << ", red: " << red << '\n';
			if ((s[l] == 'R' || blue < red) && l <= r) {
				if (s[l] == 'B') {
					blue--;
				} else {
					red--;
				}
				l++;
			} else {
				r++;
				if (s[r] == 'B') {
					blue++;
				} else {
					red++;
				}
			}
		}
		//cerr << "----------------------\n";
		//cerr << l << ' ' << r << '\n';
		//cerr << "----------------------\n";
		if (r-l == n/2-1) {
			cout << l << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}

	return 0;
}
