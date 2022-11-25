#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

const int MAX = 1e6+10;

void solve(void) {
	int n;

	cin >> n;

	int h[n];

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int ar[MAX], ans = 0;

	for (int i = 0; i < MAX; i++) {
		ar[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		if (ar[h[i]]) {
			ar[h[i]]--;
		} else {
			ans++;
		}
		ar[h[i]-1]++;
	}

	cout << ans << endl;
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
