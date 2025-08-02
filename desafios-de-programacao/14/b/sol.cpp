#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

typedef complex<ll> P;

#define X real()
#define Y imag()

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		ll x, y;
		cin >> x >> y;
		P a = {x, y};
		cin >> x >> y;
		P b = {x, y};
		cin >> x >> y;
		P c = {x, y};

		ll det = a.X * b.Y + b.X * c.Y + c.X * a.Y - (a.Y * b.X + b.Y * c.X + c.Y * a.X);

		cout << (det > 0 ? "LEFT" : (det < 0 ? "RIGHT" : "TOUCH")) << '\n';
	}
	return 0;
}
