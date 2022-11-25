#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'
#define MAX 105

void solve(void) {
	int n;
	int a[MAX], d[MAX], b[MAX];
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	
	a[0] = b[0] = d[0];
	
	for (int i = 1; i < n; i++) {
		a[i] = d[i] + a[i-1];
		b[i] = b[i-1] - d[i];
		if (b[i] < 0) 
			b[i] = d[i] + b[i-1];
		if (b[i] != a[i]) {
			cout << "-1" << endl;
			return;
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
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
