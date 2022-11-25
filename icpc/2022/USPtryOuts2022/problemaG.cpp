#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	string a;

	cin >> a;

	char aux = '\0';

	for (int i = 0; i < a.length(); i++) {
		if (a[i] != a[i+1] && a[i] != aux) {
			a.insert(i+1, 1, a[i]);
		}
		aux = a[i];
	}

	cout << a << endl;	
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
