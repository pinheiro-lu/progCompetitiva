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
		int n, x;
		cin >> n >> x;

		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int a; cin >> a;
			sum += a;
		}
		if (sum / n == x && sum % n == 0) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}

	return 0;
}
