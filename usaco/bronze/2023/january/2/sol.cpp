#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> nec(100);

struct Air{
	int a, b, p, m;
};

vector<Air> airs;

void solve() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int s, t, c;
		cin >> s >> t >> c;
		for (int j = s-1; j <= t-1; ++j) {
			nec[j]+=c;
		}
	}

	for (int i = 0; i < m; ++i) {
		int a, b, p, m;
		cin >> a >> b >> p >> m;
		airs.push_back({a-1, b-1, p, m});
	}

	int ans = INT_MAX;
	for (int i = 1; i < (1 << m); ++i) {
		vector<int> used_air;
		for (int j = 0; j < m; ++j) {
			if (i & (1 << j)) {
				used_air.push_back(j);
				cerr << "used_air: " << j << '\n';
			}
		}
		int price = 0;
		vector<int> cob(100);
		for (int x : used_air) {
			auto &s = airs[x].a;
			auto &t = airs[x].b;
			auto &p = airs[x].p;
			price += airs[x].m;
			for (int j = s; j <= t; ++j) {
				cob[j] += p;
			}
		}

		bool ok = true;
		for (int j = 0; j < 100; ++j) {
			if(nec[j]) cerr << "nec: " << nec[j] << " cob: " << cob[j] << '\n';
			if (nec[j] > cob[j]) {
				ok = false;
				//cerr << "falhouuuuu\n";
			}
		}

		cerr << "price: " << price << " ans: " << ans << '\n';
		if (ok) ans = min(ans, price);
	}

	cout << ans << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
