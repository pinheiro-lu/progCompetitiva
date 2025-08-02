#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 50;
array<int, N> a;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			a[i] = s.size();
		}
		int sum = 0;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			cerr << i << ": " << a[i] << '\n';
			if (sum + a[i] <= m) {
				sum += a[i];
				ans++;
			} else {
				break;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
