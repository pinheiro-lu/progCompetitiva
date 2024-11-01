#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> n) {
		int custo;
		cin >> custo;
		int ans = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			sum = max(0, sum + x - custo);
			ans = max(ans, sum);
		}
		cout << ans << '\n';
	}
	return 0;
}
