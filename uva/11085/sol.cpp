#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <vector<int>> v;

vector<int> row(8);
vector<int> ansAtual(8);
int rw, ld, rd;
int counter;

void backtrack(int c) {
	if (c == 8) {
		v.push_back(ansAtual);
		return;
	}
	for (int r = 0; r < 8; ++r) {
		if ((1 << r) & rw || 
			(1 << (r-c + 7)) & ld || 
			(1 << (r+c)) & rd) continue;
		rw |= (1 << r);
		ld |= (1 << (r-c + 7));
		rd |= (1 << (r + c));
		ansAtual[c] = r;
		backtrack(c+1);
		rw &= ~(1 << r);
		ld &= ~(1 << (r-c + 7));
		rd &= ~(1 << (r + c));
	}
}


void solve() {
	int ans = 8;

	for (auto x : v) {
		int aux = 0;
		for (int i = 0; i < 8; ++i) {
			if (x[i] != row[i]) ++aux;
		}
		ans = min(ans, aux);
	}

	cout << "Case " << ++counter << ": " << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	backtrack(0);

	while (cin >> row[0]) {
		--row[0];
		for (int i = 1; i < 8; ++i) {cin >> row[i]; --row[i];}
		solve();
	}

	return 0;
}
