#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	double c;
	cin >> c;
	assert(c <= 1000 && c >= 0);
	double k = c + 273.15;
	double f = c * 1.8 + 32;
	cout << fixed << setprecision(5) << k << ", " << f << '\n';

	return 0;
}
