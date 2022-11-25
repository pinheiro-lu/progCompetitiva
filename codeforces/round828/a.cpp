#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	int n;

	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	string s;

	cin >> s;

	char b[100];

	for (int i = 0; i < 100; i++) {
		b[i] = '\0';
	}

	for (int i = 0; i < n; i++) {
		if (b[a[i]] == '\0') {
			b[a[i]] = s[i];
		} else if (b[a[i]] != s[i]) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;
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
