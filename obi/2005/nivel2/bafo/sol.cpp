#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int r, a, b;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt = 1;

	while (true) {
		cin >> r;
		if (!r) break;
		int a = 0, b = 0;
		for (int i = 0; i < r; ++i) {
			int x, y;
			cin >> x >> y;
			a+=x, b+=y;
		}

		cout << "Teste " << cnt++ << '\n';
		cout <<  (a > b ? "Aldo" : "Beto") << '\n';
		cout << '\n';
	}

	return 0;
}
