#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	ll a, b, c;
	char d;

	cin >> a >> b >> c >> d;
	
	switch (d) {
		case 'A':
			a+=(3*b/2+5*c/2) + ((double) (3.0*b)/2.0 - 3*b/2 + (double) (5.0*c)/2.0 - 5*c/2);
			cout << a << '\n';
			break;
		case 'B':
			b += (2 * a / 3 + 5 * c / 3) + ((double)(2.0 * a) / 3.0 - 2 * a / 3 + (double)(5.0 * c) / 3.0 - 5 * c / 3);
			cout << b << '\n';
			break;
		case 'C':
			c += (2 * a / 5 + 3 * b / 5) + ((double)(2.0 * a) / 5.0 - 2 * a / 5 + (double)(3.0 * b) / 5.0 - 3 * b / 5);
			cout << c << '\n';
			break;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

