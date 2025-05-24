
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5 + 5;

array<int, N> a;

int n, k;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.begin() + n);
	int ans = 0;
	for (int i = 0, j = 1; i < n; ++i) {
		int s = a[j] - a[i];
		while (j < n && s < k) {
			++j;
			s = a[j] - a[i];
		}
		if (s == k) {
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
