#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

typedef complex<double> P;

#define X real()
#define Y imag()

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	P a, b, c;
	double x, y;

	cin >> x >> y;
	a = {x, y};
	cin >> x >> y;
	b = {x, y};
	cin >> x >> y;
	c = {x, y};

	double per = abs(a - b) + abs(b - c) + abs(c - a);
	double area = a.X * b.Y + b.X * c.Y + c.X * a.Y - (a.Y * b.X + b.Y * c.X + c.Y * a.X);
	area = abs(area) / 2.0;
	cout << fixed << setprecision(4) << per << " " << area << '\n';

	return 0;
}
