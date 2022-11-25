#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

void solve(void) {
	int n, m;

	cin >> n >> m;
	
	if (n % 2) cout << n/2+1;
	else cout << n/2;
	cout << ' ';
	if (m % 2) cout << m/2+1;
	else cout << m/2;
	cout <<endl;
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
