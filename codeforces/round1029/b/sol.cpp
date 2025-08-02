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
		for (int i = 1; i <= n; i+=2) {
			cout << i << " ";
		}
		n -= n % 2;
		for (int i = n; i >= 2; i-=2) {
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}
