#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (true) {
		int x, y, z, aux;
		char ig;

		double a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		x = a*100;
		y = b*100;
		z = c*100;
		/*cin >> x >> ig;
		if (ig != '.') break;
		cin >> aux;
		x *= 100;
		x += aux*10;
		cin >> y >> ig >> aux;
		y *= 100;
		y += aux*10;
		cin >> z >> ig >> aux;
		z *= 100;
		z += aux*10;
		*/
		//cerr << x << ' ' << y << ' ' << z << '\n';
		int p, m, g;
		cin >> p >> m >> g;
		int ug, um, up;
		ug = (x/30) * (y/30) + 2 * (x/30) * (z/30) + 2 * (y/30) * (z/30);
		um = max(0, (x/15) * (y/15) + 2 * (x/15) * (z/15) + 2 * (y/15) * (z/15) - 4* ug);
		up = max(0, (x/5) * (y/5) + 2 * (x/5) * (z/5) + 2 * (y/5) * (z/5) - 4*9* ug - 9 * um);
		if (ug > g) {
			um += 4 * (ug-g);
			ug = g;
		}
		if (um > m) {
			up += 9 * (um-m);
			um = m;
		}
		if (up > p) {
			cout << "impossivel\n";
		} else {
			cout << up << ' ' << um << ' ' << ug << '\n';
		}
	}
	return 0;
}
