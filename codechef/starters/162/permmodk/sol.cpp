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
		if (k == 1) {
			cout << "-1\n";
			continue;
		}
		if (k == 2 && n & 1) {
			cout << "-1\n";
			continue;
		}
		vi a(n);
		bool valid = true;
		for (int i = 0; i < n - n %k; i++) {
			a[i] = i % k;
			if (a[i] % k == 0) a[i] += k;
			a[i] += i/k*k;
		}

		if (n % k != 0) a[n-n%k]=n;
		for (int i = n - n % k+1; i < n; ++i) {
			a[i] = i;
		}

		if (n % k == 1) {
			swap(a[n-1], a[n-2]);
		}


		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
