#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << min(a, b) << ' ' << max(a, b) << '\n';
	}

	return 0;
}
