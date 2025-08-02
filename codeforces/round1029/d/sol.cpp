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
		int n; cin >> n;
		vi a(n);
		int sum = 0;
		int sum_n = (1 + n) * n / 2;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}



	return 0;
}
