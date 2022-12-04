#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	ll a[n][n];
	ll sum = 0;
	for (int i = 0; i < n; i++) 
	       for (int j = 0; j < n; j++){
		       cin >> a[i][j];
		       sum += a[i][j];
	       }
	ll mn = 10e9 + 10;

	for (int i = 0; i < n; i++) {
		mn = min(mn, a[i][n-i-1]);
	}
	cout << sum - mn;
	return 0;
}
