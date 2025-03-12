#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		string s; cin >> s;

		int at = '2';
		int sum = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != at) {
				++sum;
			}
			at = s[i];
		}

		for (int i = 0; i < s.size()-1; ++i) {
			if (s[i] == '0' && s[i+1] == '1') {
				--sum;
				break;
			}
		}

		cout << sum << '\n';
	}

	return 0;
}
