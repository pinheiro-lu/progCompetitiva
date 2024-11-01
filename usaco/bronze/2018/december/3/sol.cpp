#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> fs_barn(10);
vector<int> sc_barn(10);

int sum;
set<int>readings;

void rec(int bkt, int vol) {
	if (bkt == 4) {
		cerr << "terminating with sum = " << sum << " veio com vol " << vol << '\n';
		readings.insert(sum);
		return;
	}
	if (bkt & 1) {
		//cerr << "botando no segundo\n";
		sc_barn.push_back(vol);
		for (int &x : sc_barn) {
	//		cerr << x << ' ';
		}
		//cerr << '\n';
		for (int &x : sc_barn) {
			if (x == 0) continue;
			int aux = x;
			sum -= x;
			x = 0;
			cerr << "x2 = " << x << '\n';
			rec(bkt+1, aux);
			x = aux;
			sum += x;
		}
		sc_barn.pop_back();
	} else {
	//	cerr << "botando no primeiro\n";
		fs_barn.push_back(vol);
		for (int &x : fs_barn) {
			if (x == 0) continue;
			int aux = x;
			sum += x;
			x = 0;
//			cerr << "x1 = " << x << '\n';
			rec(bkt+1, aux);
			x = aux;
			sum -= x;
		}
		fs_barn.pop_back();
	}
}

void solve() {
	for (int i = 0; i < 10; ++i) {
		cin >> fs_barn.at(i);
	}
	for (int i = 0; i < 10; ++i) {
		cin >> sc_barn.at(i);
	}

	rec(0, 0);

	cout << readings.size() << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);

	while (t--) solve();

	return 0;
}
