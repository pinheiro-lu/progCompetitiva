#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define f first
#define s second

int n;
vector<ll> a;
vector<vector<pair<ll, ll>>> dp;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n) {
		a.resize(n);
		dp.assign(2, vector<pair<ll, ll>>(n));
		for (int i = 0; i < n; ++i) {
			cin >> a.at(i);
		}
		for (int i = 0; i < n; ++i) {
			dp.at(0).at(i) = make_pair(0, a.at(i));
		}
		for (int i = 1; i < n; ++i) {
			for (int l = 0, r = l+i; r < n; ++l, ++r) {
				auto sol1 = dp.at((i+1) % 2).at(l+1); //(l+1, r)
				auto sol2 = dp.at((i+1) % 2).at(l); //(l, r-1)
				//cerr << "aqui vai\n";
				auto &at = dp.at(i % 2);
				if (i % 2 == 0) {
					if (a.at(l) + sol1.second > a.at(r) + sol2.second) {
						sol1.second += a.at(l);
						at.at(l) = sol1;
					} else {
						sol2.second += a.at(r);
						at.at(l) = sol2;
					}
				} else {
					if (a.at(l) + sol1.first > a.at(r) + sol2.first) {
						sol1.first += a.at(l);
						at.at(l) = sol1;
					} else {
						sol2.first += a.at(r);
						at.at(l) = sol2;
					}
				}
			}
			//cerr << "cleared\n";
		}
		cout << dp.at(1).at(0).first << '\n';
		//cerr << "acessei\n";
	}

	return 0;
}

