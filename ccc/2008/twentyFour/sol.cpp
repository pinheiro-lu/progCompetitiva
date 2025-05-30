#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> hand(4);
vector<int> ops(3);
vector<int> open(4);
vector<int> close_par(4);
vector<int> const_hand(4);

bool valid;
int ans;

void perform (int st, int end) {
	open.at(st) = 5;
	for (int j = 0; j < (end-st) * (end-st); ++j) {
		for (int i = st; i < end; ++i) {
			switch (ops.at(i)) {
				case 0:
					hand.at(i) += hand.at(i+1);
					hand.at(i+1) = 0;
					break;
				case 1:
					hand.at(i) -= hand.at(i+1);
					hand.at(i+1) = 0;
					break;
				case 2:
					hand.at(i) *= hand.at(i+1);
					hand.at(i+1) = 1;
					break;
				case 3:
					if (!hand.at(i+1) || hand.at(i) % hand.at(i+1)) {
						valid = false;
						break;
					}
					hand.at(i) /= hand.at(i+1);
					hand.at(i+1) = 1;
					break;
			}
		}
	}
}

char operator_(int x) {
	int i = ops.at(x);
	return i == 0 ? '+'
		: i == 1 ? '-'
		: i == 2 ? '*'
		: '/';
}

void rec_parentheses(int par) {
	if (par == 4) {
//		if (close_par.at(0) != 1 && close_par.at(1) != 1) {
//		for (int i = 0; i < 4; ++i) {
//			cerr << close_par.at(i) << ' ';
//		}
//		cerr << '\n';
//		}
		vector<int> aux_open(open);
		vector<int> aux_close(close_par);
		sort(open.begin(), open.end());
		sort(close_par.begin(), close_par.end());
		for (int i = 0; i < close_par.size(); ++i) {
			for (int j = open.size()-1; j >= 0; --j) {
				if (close_par.at(i) >= open.at(j)) {
					perform(j, i);
				}
			}
		}
		perform(0, 3);
//		if (ops.at(0) == 2 && ops.at(1) == 2 && ops.at(2) == 1) {
//			for (int i = 0; i < 3; ++i) {
//				cerr << const_hand.at(i) << ' ' << operator_(i) << ' ';
//			}
//			cerr << const_hand.at(3) << " = " << hand.at(0) << '\n';
//			for (int i = 0; i < 3; ++i) {
//				cerr << hand.at(i) << ' ' << operator_(i) << ' ';
//			}
//			cerr << hand.at(3) << " = " << hand.at(0) << '\n';
//			for (int i = 0; i < 4; ++i) {
//				cerr << close_par.at(i) << ' ';
//			}
//			cerr << '\n';
//		}
//
		if (valid && hand.at(0) <= 24) {
			ans = max(ans, hand.at(0));
		}
		open = aux_open;
		close_par = aux_close;
		return;
	}
		
	for (int i = 0; i < 3; ++i) {
		open.at(par) = i;
		for (int j = i+1; j < 4; ++j) {
			close_par.at(par) = j;
			rec_parentheses(par+1);
		}
	}
}

void rec(int op) {
	if (op == 3) {
		rec_parentheses(0);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		ops.at(op) = i;
		rec(op+1);
	}
}
		

void solve() {

	for (int i = 0; i < 4; ++i) {
		cin >> const_hand.at(i);
	}

	do {
		hand = const_hand;
		rec(0);
	} while (next_permutation(const_hand.begin(), const_hand.end()));

	cout << ans << '\n';

	ans = 0;

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	while (t--) solve();

	return 0;
}
