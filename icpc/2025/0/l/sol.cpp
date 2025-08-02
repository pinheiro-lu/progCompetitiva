#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll m; cin >> m;

	cout << ceil(log2(m*8e6));

	return 0;
}
