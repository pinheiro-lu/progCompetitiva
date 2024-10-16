#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

int n, k;

int x;

void solve() {
	cin >> x;
	int ans;

	if ((x+1)*x/2 >= k) {
		ans = ceil((-1 + sqrt(1 + 8*k))/2);
	} else {
		ans = x;
		int falta = k - (x+1)*x/2;
		cerr << "falta " << falta << '\n';
		long double d = (0.5-2.0*(long double) x + (long double) sqrt((2.0*x-0.5)*(2.0*x-0.5)+4.0*falta))/2;
		cerr << d << '\n';
		int n = floor(d);
		if(n) {
		ans += 2*n;
		falta -= (x+x+n)*n;
		}
		cerr << "falta " << falta << '\n';
		if (falta > 0) ++ans;
		falta -= x+ n;
		if (falta > 0) ++ans;
	}
	cout << ans << '\n';


}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);

	cin >> k >> n;
	while (n--) solve();

	return 0;
}
