#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define f first
#define s second

const ll MAXR = 1e5+1;

array<ll, MAXR+1> sol;
array<ll, MAXR+1> last_y;
ll not_filled=1;

void solve(ll r) {
	for (ll bl = not_filled; bl <= r; ++bl) {
		ll y = min((ll)sqrt((r+1)*(r+1)-bl*bl), bl);
		if (y*y >= (r+1)*(r+1)-bl*bl) --y;
		//cerr << "y " << y << " r " << r << " bl " << bl << '\n';
		//for (y = last_y.at(bl); bl*bl+(y+1)*(y+1) < (r+1)*(r+1) && y+1 <= bl; ++y);
		ll fill = 0;
		ll delta = y-last_y.at(bl);
		if (y == bl) {
			fill = (delta-1)*8 + 4;
			++not_filled;
			//cerr << r << ' ' << not_filled << '\n';
		}
		else fill = (delta)*8;
		if (y == delta) fill += 4;
		last_y.at(bl) = y;
		sol.at(r) += fill;
	}

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	//for (ll i = 1; i < 2000; ++i) cout << i << ' ' << sol.at(i) << '\n';

	ll tt;
	cin >> tt;
	while (tt--) {
		fill(sol.begin(), sol.end(), 0);
		fill(last_y.begin(), last_y.end(), 0);
		not_filled = 1;
		ll r;
		cin >> r;
		solve(r-1);
		solve(r);
		cout << sol.at(r) << '\n';
	}

	return 0;
}
