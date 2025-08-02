#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 2e5;
int n;
array<pair<int, int>, N> a;

ll calc(int id) {
	int mn_x = 1e9, mx_x = 1, mn_y = 1e9, mx_y = 1;
	for (int i = 0; i < n; i++) {
		if (i == id) continue;
		mn_x = min(mn_x, a[i].f);
		mx_x = max(mx_x, a[i].f);
		mn_y = min(mn_y, a[i].s);
		mx_y = max(mx_y, a[i].s);
	}
	if (n == 1) return 1;
	ll ans = (mx_x - mn_x + 1LL) * (mx_y - mn_y + 1LL);
	if (ans == n-1) {
		ans = min((mx_x - mn_x + 2LL) * (mx_y - mn_y + 1LL),
		          (mx_x - mn_x + 1LL) * (mx_y - mn_y + 2LL));
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		int id_mn_x = 0, id_mx_x = 0, id_mn_y = 0, id_mx_y = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i].f >> a[i].s;
			if (a[i].f < a[id_mn_x].f) id_mn_x = i;
			if (a[i].f > a[id_mx_x].f) id_mx_x = i;
			if (a[i].s < a[id_mn_y].s) id_mn_y = i;
			if (a[i].s > a[id_mx_y].s) id_mx_y = i;
		}
		cout << min({calc(id_mn_x), calc(id_mn_y), calc(id_mx_x), calc(id_mx_y)}) << '\n';
	}

	return 0;
}
