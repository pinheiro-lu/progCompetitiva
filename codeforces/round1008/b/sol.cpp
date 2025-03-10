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
		int n, k;
		cin >> n >> k;
		if (k & 1) {
			for (int i = 0; i < n-1; ++i) {
				cout << n << ' ';
			}
			cout << n-1 << '\n';
		} else {
			for (int i = 0; i < n-2; ++i) {
				cout << n-1 << ' ';
			}
			cout << n << ' ' << n-1 << '\n';
		}
	}

	return 0;
}
