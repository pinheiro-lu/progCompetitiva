#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 10

void solve() {
	int x, y, z;

	x = 1 + rand() % MAX;
	y = 1 + rand() % MAX;
	z = 1 + rand() % MAX;

	ll k;
	k = 1 + rand() % (x*y*z);

	cout << x << " " << y << " " << z << " " << k << endl;

}

signed main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(atoi(argv[1]));

	int t = 100;
	cout << t << '\n';

	while (t--) solve();

	return 0;
}