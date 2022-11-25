#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	int n, q, np = 0, ni = 0;
	ll sump = 0, sumi = 0;

	cin >> n >> q;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			sump += a[i];
			np++;
		}
		else {
			sumi += a[i];
			ni++;
		}
	}

	int t[q], x[q];

	ll sum = sumi + sump;

	for (int i = 0; i < q; i++) {
		cin >> t[i] >> x[i];
		switch (t[i]) {
			case 0:
			sum+=np * x[i];
			if (x[i] % 2 != 0) {
				ni += np;
				np = 0;
			}
			break;
			case 1:
			sum+=ni* x[i];
			if (x[i] % 2 != 0) {
				np += ni;
				ni = 0;
			}
			break;
		}
		cout << sum << endl;
	}
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
