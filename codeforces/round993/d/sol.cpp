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
		int n; cin >> n;
		vector<bool> b(n+1);
		vi a(n);
		int f = 1;
		for (int &x : a) cin >> x;
		for (int i = 0; i < n; ++i) {
			if (b.at(a.at(i))) {
				while (b.at(f)) ++f;
				b.at(f) = true;
				cout << f << ' '; 
				++f;
			} else {
				b.at(a.at(i)) = true;
				cout << a.at(i) << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
