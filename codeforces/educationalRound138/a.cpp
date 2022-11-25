#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

int sx[10], sy[10];
int t[10][10];

void solve(void) {
	int n, m;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			t[i][j] = 0;
		}
	}

	for (int i = 0; i < 10; i++) {
		sx[i] = 0; sy[i] = 0;
	}

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		t[x][y] = 1;
		sx[x]++; sy[y]++;
	}

	if (n > m) cout << "YES\n";
	else cout << "NO\n";

	


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
