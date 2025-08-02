#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	string s, t;
	cin >> s >> t;
	int cnt_s = 0, cnt_t = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '*') cnt_s++;
		if (t[i] == '*') cnt_t++;
	}

	cout << fixed << setprecision(2) << (double)(cnt_s-cnt_t)/cnt_s << '\n';

	return 0;
}
