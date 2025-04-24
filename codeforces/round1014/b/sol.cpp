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
		string a, b;
		cin >> a >> b;
		int even = 0, odd = 0;
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				odd += a.at(i) == '0';
				even += b.at(i) == '0';
			} else {
				odd += b.at(i) == '0';
				even += a.at(i) == '0';
			}
		}
		//cerr << even << " " << odd << "\n";
		if (even >= (n + 1) / 2 && odd >= n / 2) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}


	return 0;
}
