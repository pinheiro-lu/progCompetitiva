#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> hand(4);
vector<int> ops(3);
vector<int> open(4);
vector<int> close(4);

void rec(int op) {
	if (op == 3) {
		for (int i = 0; i < 4; ++i) {
			open.at(0) = i;


	for (int i = 0; i < 4; ++i) {
		ops.at(op) = i;
		rec(op+1);
	}
}
		

void solve() {
	for (int i = 0; i < 4; ++i) {
		cin >> hand.at(i);
	}

	do {
		rec(0);
	} while (next_permutation(hand.begin(), hand.end());
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
