#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

const int MAX = 1e6+10;

void solve(void) {
	int n;

	cin >> n;

	int card[15];

	for (int i = 0; i < 15; i++) {
		card[i] = 4;
	}

	int m1, m2, j1, j2;

	cin >> j1 >> j2;
	cin >> m1 >> m2;

	card[m1]--;
	card[m2]--;
	card[j1]--;
	card[j2]--;

	int c[n];

	int cm = 0;

	for (int i = 0; i < n; i++) {
		cin >> c[i];
		cm += min(c[i], 10);
		card[c[i]]--;
	}

	int pm = min(m1, 10) + min(m2, 10) + cm;
	int pj = min(j1, 10) + min(j2, 10) + cm;

	if (pm >= pj) {
		if(card[23-pm]) {
			cout << 23 - pm << endl;
			return;
		}
		if (23-pm == 10) {
			if (card[11]) {
				cout << 11 << endl;
				return;
			}
			if (card[12]) {
				cout << 12 << endl;
				return;
			}
			if (card[13]) {
				cout << 13 << endl;
				return;
			}
			cout << "-1*"<< endl;
			return;
		}
	}

	if (pj > 13) {
		int i = 24-pj;
		while (i <= 13) {
			if (pm + i < 24 && card[i]) {
				cout << i << endl;
				return;
			}
			i++;
		}
	}
	cout << -1 << endl;
	return;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	
	//cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}
