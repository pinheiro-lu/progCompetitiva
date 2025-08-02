#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	s.insert(s.begin(), 'b');
	s.push_back('b');
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'a' && (s[i - 1] == 'a' || s[i + 1] == 'a')) {
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
