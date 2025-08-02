#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef complex<int> P;

#define f first
#define s second
#define X real()
#define Y imag()

const int N = 2002;

array<P, N> vertex;
int n;

bool inside (int idx) {
	int touchs = 0;
	P p = vertex[idx];
	cerr << "ant: " << vertex[idx-1] << " p: " << p << " prox: " << vertex[idx+1] << '\n';
	for (int i = 1; i <= n; ++i) {
		P a = vertex[i-1], b = vertex[i];
		if (a.X == b.X && p.X == a.X && (p.Y < max(a.Y, b.Y))) {
			touchs++;
			continue;
		}
		if (a.X > b.X) swap(a, b);
		if (a.X < p.X && p.X < b.X && p.Y < a.Y + (b.Y - a.Y) * (p.X - a.X) / (b.X - a.X)) {
			touchs++;
			cerr << "touch: " << a << " " << b << '\n';
		}
	}
	cerr << "idx: " << idx << " touchs: " << touchs << '\n';
	return (touchs & 1);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		vertex[i] = {u, v};
	}
	vertex[n] = vertex[0];
	vertex[n+1] = vertex[1];

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		//cerr << "ant: " << vertex[i-1] << " p: " << vertex[i] << " prox: " << vertex[i+1] << '\n';
		if (vertex[i-1].Y > vertex[i].Y && vertex[i].Y < vertex[i+1].Y && inside(i)) {
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
