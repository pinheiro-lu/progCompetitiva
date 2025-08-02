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
		int n; cin >> n;
		bool found = false;
		for (int i = 0; i * i <= n; i++) {
			if (i * i == n) {
				cout << i << ' ' << "0\n";
				found = true;
				break;
			}
		}
		if (found) continue;
		cout << "-1\n";
	}

	return 0;
}
