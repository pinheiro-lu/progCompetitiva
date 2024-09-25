#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a, b, c, d, x, y, z, w, m, n, o, p;
bool ret[3000][3000] = {0};

void solve() {
	cin >> a >> b >> c >> d >> x >> y >> z >> w >> m >> n >> o >> p;
	a +=1000;
	b +=1000;
	c +=1000;
	d +=1000;
	x +=1000;
	y +=1000;
	z +=1000;
	w +=1000;
	m +=1000;
	n +=1000;
	o +=1000;
	p +=1000;
	cerr << "nums atualizados " << '\n';

	for (int i = a; i < c; ++i) {
		for (int j = b; j < d; ++j) {
			ret[i][j] = true;
		}
	}
	for (int i = x; i < z; ++i) {
		for (int j = y; j < w; ++j) {
			ret[i][j] = true;
		}
	}
	for (int i = m; i < o; ++i) {
		for (int j = n; j < p; ++j) {
			ret[i][j] = false;
		}
	}

	int sum = 0;
	for (int i = 0; i <= 2000; ++i) {
		for (int j = 0; j <= 2000; ++j) {
			sum += ret[i][j];
		}
	}

	cout << sum << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	while (t--) solve();

	return 0;
}
