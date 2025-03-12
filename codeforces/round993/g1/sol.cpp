#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vi r(n), spi(n);
		set <int> s;
		for (int i = 0; i < n; i++) {
			s.insert(i);
		}
		for (int i = 0; i < n; i++) {
			cin >> r[i];
			--r[i];
			spi[r[i]]++;
			s.erase(r[i]);
		}

		int ans = 1;
		set <int> aux;
		while (!s.empty()) {
			for (int x : s) {
				spi[r[x]]--;
				if (spi[r[x]] == 0) aux.insert(r[x]);
			}
			s.clear();
			++ans;
			if (aux.empty()) break;
			for (int x : aux) {
				spi[r[x]]--;
				if (spi[r[x]] == 0) s.insert(r[x]);
			}
			aux.clear();
			++ans;
		}

		cout << ans + 1 << '\n';
	}

	return 0;
}
