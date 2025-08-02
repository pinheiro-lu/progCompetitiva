#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int c, g;
	cin >> c >> g;
	if (c == 1) cout << "vivo e morto";
	else if (g == 0) cout << "morto";
	else cout << "vivo";

	return 0;
}
