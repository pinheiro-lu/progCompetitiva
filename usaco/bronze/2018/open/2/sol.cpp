#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;
int pos[101];
int order[101];
int cow[101];

void solve() {
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i) {
		cin >> order[i];
	}

	for (int i = 0; i < k; ++i) {
		int c, p;
		cin >> c >> p;
		pos[p] = c;
		cow[c] = p;
	}

	int x = n;
	for (int i = m-1; i >= 0; --i) {
		if (order[i] == 1) break;
		if (!cow[order[i]]) {
			if (!pos[x]) {
				cow[order[i]] = x;
				pos[x] = order[i];
				--x;
			} else {
				--x, ++i;
			}
		} else {
			x = cow[order[i]]-1;
		}
	}

	x = 1;
	for (int i = 0; i < m; ++i) {
		if (!cow[order[i]]) {
			if (!pos[x]) {
				cow[order[i]] = x;
				pos[x] = order[i];
				++x;
			} else {
				++x, --i;
			}
		} else {
			x = cow[order[i]]+1;
		}
	}

	int i = 1;
	cerr << "finalizando\n";

	if (cow[1]) {
		cout << cow[1] << '\n';
		return;
	}

	while (true) {
		if (!pos[i]) {
			cout << i << '\n';
			break;
		}
		++i;
	}


}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);
	int t = 1;

	while (t--) solve();

	return 0;
}
