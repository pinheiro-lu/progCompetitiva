#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e7;
ll v[N];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	int k;
	cin >> n >> k;

	int cnt = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			v[cnt++] = i;
			if (i * i != n) {
				v[cnt++] = n / i;
			}
		}
	}
	sort(v, v + cnt);
	if (k <= cnt) {
		cout << v[k-1] << '\n';
	} else {
		cout << -1 << '\n';
	}

	return 0;
}
