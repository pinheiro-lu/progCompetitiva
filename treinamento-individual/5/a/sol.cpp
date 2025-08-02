#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int solve(int b, int p, int f, int h, int c)  {
	int ans = 0;
	while (b > 1 && (p > 0 || f > 0)) {
		b -= 2;
		if (p) {
			--p;
			ans += h;
		} else {
			--f;
			ans += c;
		}
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int b, p, f, c, h;
		cin >> b >> p >> f >> h >> c;
		int ans = max(solve(b, p, f, h, c), solve(b, f, p, c, h));
		cout << ans << '\n';
	}

	return 0;
}
