#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int c, r, n, s;
vector<vi> rua;
vi ina;

// onde quero ir, distancia que falta, simulações restantes
int solve(int at, int d, int res) {
	int sum = 0;
	//cerr << "solving for " << at << '\n';
	for (int &x : ina) {
		sum+=x;
	}
	int prox = at;
	//cerr << "dist " << d << '\n';
	if (!d) {
		sum -= ina.at(at);
		ina.at(at) = 0;
		int prox_ina = -1;
		for (int i = 0; i < c; ++i) {
			//cerr << "testando " << i << " mas " << ina.at(i) << '\n';
			if (ina.at(i) > prox_ina && rua.at(at).at(i)) {
				prox_ina = ina.at(i);
				prox = i;
			}
		}
		d = rua.at(at).at(prox);
	}
	if (!res) return sum;
	for (int &x : ina) {
		++x;
	}
	//cerr << "sum " << sum << '\n';
	return sum + solve(prox, d-1, res-1);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> c;
	while (c) {
		cin >> r >> n >> s;
		--s;
		rua.assign(c, vi(c, 0));
		ina.assign(c, 0);
		for (int i = 0; i < r; ++i) {
			int x, y, d;
			cin >> x >> y >> d;
			--x, --y;
			rua.at(x).at(y) = d;
			rua.at(y).at(x) = d;
		}
		cout << solve(s, 0, n) << '\n';
		cin >> c;
	}

	return 0;
}
