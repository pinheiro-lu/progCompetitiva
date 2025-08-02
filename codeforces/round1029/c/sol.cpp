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
		vi a(n);
		vi b(n, -1); // guarda o ultimo it do elemento
		vi gp_lst(n); // guarda o ultimo indice do grupo
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			--a[i];
		}
		int gp = 0, it = 0; // gp guarda o grupo atual, it guarda um indice que separa grupos (um grupo pode ser formado por varios indices)
		for (int i = n-1; i >= 0; i--) {
			if ((gp == 0 && b[a[i]] != -1) || (gp > 0 && gp_lst[gp-1] < b[a[i]])) {
				cerr << it << ' ' << gp << '\n';
				++it, ++gp;
			} else if ((gp > 1 && gp_lst[gp-2] >= b[a[i]]) || b[a[i]] == -1) {
				while (gp > 0 && gp_lst[gp-1] >= b[a[i]]) {
					--gp;
				}
			}
			gp_lst[gp] = it;
			b[a[i]] = it;
		}
		for (int i = 0; i <= gp; ++i) {
			cerr << gp_lst[i] << ' ';
		}
		cerr << '\n';
		for (int i = 0; i < n; ++i) {
			cerr << b[a[i]] << ' ';
		}
		cerr << '\n';
		cout << gp + 1 << '\n';
	}
	return 0;
}
