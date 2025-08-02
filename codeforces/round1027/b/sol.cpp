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
		int n, k; cin >> n >> k;
		string s;
		cin >> s;
		int cnt = 0;
		for (char c : s) {
			if (c == '1') ++cnt;
		}
		int dif = abs(cnt - (n - cnt));
		int mn = dif/2;
		int mx = cnt/2 + (n - cnt)/2;
		cout << (mn <= k && k <= mx && ((k-mn) % 2 == 0) ? "YES" : "NO") << '\n';
	}


	return 0;
}
