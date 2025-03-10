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
		vi b(n-1);
		for (int i = 0; i < n-1; i++) {
			cin >> b[i];
		}
		sort(b.begin(), b.end());
		vi a(n);
		a[0] = 1;
		for (int i = 1; i < n; ++i) {
			a[i] = b[i-1] - a[i-1];
		}
		for (int i = 0; i < n; ++i) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}
