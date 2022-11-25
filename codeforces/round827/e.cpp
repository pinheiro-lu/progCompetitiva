#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	int n, q;

	cin >> n >> q;

	int a[n], k[q];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < q; i++) {
		ll ans = 0;
		cin >> k[i];
		for (int j = 0; j < n; j++) {
			if (a[j] <= k[i]) {
				ans+=a[j];
			} else break;
		}
		cout << ans << ' ';
	}
	cout << endl;

}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	
	cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}
