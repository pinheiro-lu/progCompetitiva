#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 3e5;

array<int, N> a, p;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	partial_sum(a.begin(), a.end(), p.begin()+1);
	int ans = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n && p[j] - p[i-1] <= m) {
			j++;
		}
		ans = max(ans, p[j-1] - p[i-1]);
	}

	cout << ans << '\n';

	return 0;
}
