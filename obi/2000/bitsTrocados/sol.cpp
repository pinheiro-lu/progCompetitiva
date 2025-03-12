#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int v, i, j, k, l;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt = 1;
	while (true) {
		cin >> v;
		if (v == 0) break;
		i = j = k = l = 0;

		while (v) {
			if (v >= 50) {
				v -= 50;
				++i;
			} else if (v >= 10) {
				v -= 10;
				++j;
			} else if (v >= 5) {
				v -= 5;
				++k;
			} else {
				--v, ++l;
			}
		}

		cout << "Teste " << cnt++ << '\n';
		cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
		cout << '\n';
	}



	return 0;
}
