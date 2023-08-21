#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a, b, solutions;
int row[8];
int rw, ld, rd;

void backtrack(int c) {
	if(c == 8) {
		cout << ' ' << ++solutions << '\t';
		for (int i = 0; i < c; ++i) {
			cout << row[i] + 1 << ' ';
		}
		cout << '\n';
		return;
	}

	for (int r = 0; r < 8; ++r) {
		if ((c == b && r != a) ||
			(1 << r) & rw || 
			(1 << (r-c + 7)) & ld || 
			(1 << (r+c)) & rd) continue;
		row[c] = r;
		rw |= 1 << r;
		ld |= 1 << (r-c+7);
		rd |= 1 << (r+c);
		backtrack(c+1);
		rw &= ~(1 << r);
		ld &= ~(1 << (r-c+7));
		rd &= ~(1 << (r+c));
	}
}


void solve() {
	cin >> a >> b; --a, --b;

	cout << "SOLN\t   COLUMN\n #\t1 2 3 4 5 6 7 8\n\n";
	solutions = 0;
	backtrack(0);

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) {solve(); if (t) cout << '\n';};

	return 0;
}
