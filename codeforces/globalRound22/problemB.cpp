#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(void) {
	int n, k;
	
	cin >> n >> k;

	vector <ll> a(k);

	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
		
	if (k == 1) {
		cout << "yes\n";
		return;
	}
	

	vector<ll> b(k-1);
	for (int i = 0; i < k-1; i++) {
		b[i] = a[i+1]-a[i];
	}
	if (is_sorted(b.begin(), b.end()) && ((n-k+1)*b[0] >= a[0])) {
		cout << "yes\n";
	} else {
		cout << "no\n";
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
