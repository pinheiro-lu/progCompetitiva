#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int p, r;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt = 1;

	while (true) {
		cin >> p >> r;
		if (!p) break;

		vi id(p);
		for (int i = 0; i < p; ++i) cin >> id.at(i);

		while (r--) {
			int n, ord;
			cin >> n >> ord;
			for (int i = 0; i < n; ++i) {
				int x;
				cin >> x;
				if (x != ord) id.at(i) = 0;
			}
			for (auto it = id.begin(); it != id.end();) {
				if (*it == 0) id.erase(it);
				else ++it;
			}
		}

		cout << "Teste " << cnt++ << '\n';
		cout << id.at(0) << "\n\n";
	}

	return 0;
}
