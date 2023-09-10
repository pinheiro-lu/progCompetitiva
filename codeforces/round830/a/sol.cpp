#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) //printf(args)
#define endl '\n'

typedef long long ll;

int n;
int a[20], cd;

int sol(int cdm, int i) {
	if (i == n) return -1000;
	int ans = n-i;
	cdm = gcd(cdm, gcd(i+1, a[i]));
	//cout << "cdm, i:" << cdm << ' ' << i << '\n';
	if (cdm != 1) {
		ans+=sol(cdm, i+1);
	}
	return ans;
}

void solve(void) {
    cin >> n;

	cin >> a[0];
	cd = a[0];

	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		cd = gcd(cd, a[i]);
	}

	int cdm;
	int ans = 20, ansAt;
	if (cd == 1) {
		cout << "0\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		ansAt = n-i;
		cdm = gcd(cd, gcd(i+1, a[i]));
		if (cdm != 1) ansAt += sol(cdm, i+1);
		if (ansAt >= 0)
		ans = min(ans, ansAt);
	//	cout << "ans, cdm: " << ans << ' ' << cdm << '\n';
	}

	cout << ans << '\n';

}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	
    cin >> t;
	//scanf("%d", &t);
//	while (getchar() != '\n');

	while (t--)
		solve();
		
	return 0;
}
