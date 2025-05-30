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
		int need = 0;
		map<int, int> nec;
		ll ans = 0;
		int sum = 0;
		nec[1]=1;
		for (int i = 0; i < n; ++i) {
			char c;
			cin >> c;
			sum += c-'0';
			ans += nec[sum+need];
			nec[sum+need]++;
			--need;
		}

		cout << ans << '\n';
	}



	return 0;
}
