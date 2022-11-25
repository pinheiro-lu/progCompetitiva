#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //printf(args)
#define endl '\n'
#define MAXA 100004
#define MAXB 1000000006

typedef long long ll;

//int a[MAXA];
//int bfi[MAXA], bfr[MAXA];

void solve(void) {
	int n, lenr = 0, leni = 0, lenc = 0; 
	ll sum = 0;
	
	cin >> n;
	
	ll bfi[n], bfr[n];
	int a[n];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i]) cin >> bfi[leni++];
		else cin >> bfr[lenr++];
	}
	
	sort(bfi, bfi + leni);
	sort(bfr, bfr + lenr);
	
	lenc = min(leni, lenr);
//	debug("lenc = %d\n", lenc);
	
	for (int i = 0; i < lenc; i++) {
		sum+=2*(bfi[leni-1-i]+bfr[lenr-1-i]);
	}
	
	debug("sum = %ld\n", sum);
	
	for (int i = 0; i < leni-lenc; i++) {
		sum+=bfi[i];
	}
	debug("sum = %ld\n", sum);
	
	for (int i = 0; i < lenr-lenc; i++) {
		sum+=bfr[i];
	}
	
	if (leni-lenr == 0) sum-= min(bfi[0], bfr[0]);
	
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
