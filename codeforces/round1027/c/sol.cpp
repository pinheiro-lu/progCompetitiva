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
		vi a;
		while (n--) {
			int x; cin >> x;
			if (a.empty()) {
				a.push_back(x);
				continue;
			}
			if (x > a.back() + 1)
				a.push_back(x);
		}
		cout << a.size() << '\n';
	}
	return 0;
}
