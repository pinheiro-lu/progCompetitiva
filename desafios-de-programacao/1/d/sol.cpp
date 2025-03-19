#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> lin(n);
	vector<int> col(m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			lin.at(i)+=x;
			col.at(j)+=x;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (1LL << lin.at(i)) - 1LL;
		ans += (1LL << (m-lin.at(i))) - 1LL;
	}
	for (int i = 0; i < m; ++i) {
		ans += (1LL << col.at(i)) - 1LL;
		ans += (1LL << (n-col.at(i))) - 1LL;
	}
	ans-=n*m;
	cout << ans << '\n';


	return 0;
}
