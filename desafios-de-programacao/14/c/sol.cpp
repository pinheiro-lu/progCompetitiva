#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

typedef complex<ll> P;

#define X real()
#define Y imag()

const int N = 1001;

array<P, N> points;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		points[i] = P(x, y);
	}
	points[n] = points[0]; // Close the polygon

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		P a = points[i];
		P b = points[i + 1];
		ans += (a.X * b.Y - a.Y * b.X);
	}

	ans = abs(ans);

	cout << ans << '\n';

	return 0;
}
