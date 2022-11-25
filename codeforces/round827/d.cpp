#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

int coprimos[1007][1007];

bool prime (int a, int b) {
	if (coprimos[a][b] != -1) return coprimos[a][b];
	if (a % 2 == 0 && b % 2 == 0) {
		coprimos[a][b] = 0;
		return false;
	}
	if (a % 2 == 0) {
		int tmp = prime (a/2, b);
		coprimos[a][b] = tmp;
		return tmp;
	}
	if (b % 2 == 0) {
		int tmp = prime (a, b/2);
		coprimos[a][b] = tmp;
		return tmp;
	}

	int tmp = prime((max(a,b)-min(a,b))/2, min(a,b));
	coprimos[a][b] = tmp;
	return tmp;
}

void solve(void) {
	int n, sum = -1;

	for (int i = 0; i < 1007; i++) {
		coprimos[1][i] = 1;
		coprimos[i][1] = 1;
	}
	for (int i = 2; i < 1007; i++) {
		for (int j = 2; j < 1007; j++) {
			coprimos[i][j] = -1;
		}
	}

	cin >> n;

	int a[n+1];

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = n; i > 1; i--) {
		if (a[i] == 1) {
			sum = max(sum, i*2);
		}
		for (int j = i-1; j >= 1; j--) {
			if (prime(max(a[i], a[j]), min(a[i], a[j]))) {
				sum = max(sum, i+j);
			}
		}
	}

	cout << sum << endl;
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
