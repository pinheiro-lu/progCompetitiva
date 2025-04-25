#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vi p(2*n+1);
		vi cnt(2*n+1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; ++j) {
				int x;
				cin >> x;
				p.at(i+j) = x;
				cnt.at(x)++;
			}
		}
		for (int i = 1; i <=2*n; ++i) {
			if (!cnt.at(i)) {
				p.at(1) = i;
				break;
			}
		}
		for (int i = 1; i <= 2*n; ++i) {
			cout << p.at(i) << " ";
		}
		cout << "\n";
	}


	return 0;
}
