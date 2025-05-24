#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 3e5 + 1;

array<array<ll, N>, 2> a, p;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		p[i&1][i] = p[i&1][i-1] + a[i&1][i];
		p[!(i&1)][i] = p[i&1][i] + a[!(i&1)][i];
	}
	
	ll sub1 = 0, sub2 = 0;

	return 0;
}
