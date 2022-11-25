#include <bits/stdc++.h>
using namespace std;

#define debug(args...) printf(args)
#define endl '\n'

typedef long long ll;

int sx[10], sy[10];
int t[10][10];

struct A {
	int a;
	int b;

	friend bool operator< (const A & l, const A & r) {
		return l.b < r.b;
	}
};



void solve(void) {
	int n;

	cin >> n;

	int a[n+1];

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int l = 0, r = INT_MAX;

	int maxk;

	while (l <= r) {
		int k = (l+r)/2;
		
		for (int i = 1; i <=n; i++) {
			if ()
		}

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
