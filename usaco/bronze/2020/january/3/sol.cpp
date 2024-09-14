#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

int x;

void solve() {
	cin >> x;
	int ans;

	if ((x+1)*x/2 >= k) {
		ans = ceil((-1 + sqrt(1 + 8*k))/2);
	} else {
		ans = floor((-2* x - 0.5 + sqrt((2*x + 0.5)*(2*x + 0.5) -4*(3*x/2 + x*x/2 - k)))/2);
		ans *= 2;
		ans += x;
		int falta = k - ((x+1)*x/2 + (1+ans)*ans/2 + (1+ans)*x + ans*ans/2 + ans*x);
		if (falta > 0)
			ans += ceil((double)falta/(double)x);

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
