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
		int n;
		cin >> n;
		int mx = 0, sum = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			sum = max(0, sum+x);
			mx = max(mx, sum);
		}
		cout << mx << '\n';
	}

	return 0;
}
