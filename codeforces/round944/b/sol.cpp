#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		char c = s[0];
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != c) {
				swap(s[0], s[i]);
				break;
			}
		}
		if (s[0] == c) {
			cout << "NO\n";
		} else {
			cout << "YES\n" << s << '\n';
		}
	}

	return 0;
}
