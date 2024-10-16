#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int k, n;
int x;

int rec(int speed, int t, int sum) {
	if (speed <= 0) return 1e9;
	sum += speed;
	if (sum >= k) {
		if (speed > x) return 1e9;
		return t;
	}
	return min({rec(speed-1, t+1, sum), rec(speed, t+1, sum), rec(speed+1, t+1, sum)});
}

void solve() {

	cin >> x;

 	cout << rec(1,1, 0) << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> k >> n;

	while (n--) {
		solve();
	}

	return 0;
}
