#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x1, y1, x2, y2; 
	cin >> n >> x1 >> y1 >> x2 >> y2;

	if (x1 > n/2) x1 = n - x1 + 1;
	if (y1 > n/2) y1 = n - y1 + 1;
	if (x2 > n/2) x2 = n - x2 + 1;
	if (y2 > n/2) y2 = n - y2 + 1;
	cout << abs(min(x2, y2) - min(x1,y1)) << '\n';	
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}	

