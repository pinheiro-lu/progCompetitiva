#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

array<int, 11> fib;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt;
	cin >> tt;

	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= 10; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	while (tt--) {
		string ans;
		int n, m;
		cin >> n >> m;
		array<int, 3> dim;
		while (m--) {
			for (int i = 0; i < 3; ++i) {
				cin >> dim[i];
			}
			sort(dim.begin(), dim.end());
			//cerr << dim[0] << ' ' << dim[1] << ' ' << dim[2] << '\n';
			if (dim[0] >= fib[n] && dim[2] >= fib[n]+fib[n-1]) {
				//cerr << n << ": " << fib[n] + fib[n-1] << '\n';
				//cerr << "dim: " << dim[2] << '\n';
				ans += '1';
			} else {
				ans += '0';
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
