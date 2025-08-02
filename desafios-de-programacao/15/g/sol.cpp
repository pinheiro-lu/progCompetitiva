#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1000;
array<int, N> col;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		fill(col.begin(), col.end(), 0);
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			col[x-1]++;
		}
		int ans = 0, unq = 0;
		for (int i = 0; i < n; ++i) {
			if (col[i] > 1) ans++;
			if (col[i] == 1) unq++;
		}
		ans += (unq+1)/2*2;
		cout << ans << '\n';
	}

	return 0;
}
