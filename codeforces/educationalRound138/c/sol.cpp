#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;


void solve(void) {
	int n;

	cin >> n;

	int a[n+1];

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort (a+1, a + n+1, [] (int &l, int &r) { return l > r; });

	int k;
	for (k = 1; k <= n; ++k) {
		int i, l, r;
		for (i = 1, l = 1, r = n; i <= k && l <= r; ++i, ++l, --r) {
		//	cout << "i, k, l, r\n";
		//	cout << i << ' ' << k << ' ' << l << ' ' << r << '\n';
			while (l <= r && a[l] > k - i + 1) {//cout << "l: " << l << ' ';
			++l;}
			if (l > r) {
				cout << k - 1 << '\n';
				return;
			}
			//cout << '\n';
		}
//		cout << "i: " << i << '\n';
		if (i <= k) {
			cout << k - 1 << '\n';
			return;
		}
	}

	cout << k-1 << '\n';
}

			

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}
