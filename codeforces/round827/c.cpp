#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	string a[8];

	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 8; i++) {
		if (a[i] == "RRRRRRRR") {
			cout << "R" << endl;
			return;
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7; j++) {
			if (a[j][i] == '.' || a[j][i] == 'R') break;
			if (a[j][i] != a[j+1][i]) break;
			else if (j==6) {
				cout << "B" << endl;
				return;
			}
		}
	}

}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}
