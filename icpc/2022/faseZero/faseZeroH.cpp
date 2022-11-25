#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	ll c;

	cin >> c;

	ll n = (-1.0 + sqrt(1.0+4.0*3.0*(2.0*(long double)c)))/6.0;

	cout << n << endl;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	
	cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}