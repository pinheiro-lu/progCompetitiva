#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, l;

	cin >> n >> l;

	vector<int>a(n);


	int sol = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i-1] > sol) sol = a[i]-a[i-1];
	}

	double ans = (double) sol/2;

	if (a[0] > ans) ans = a[0];
	if (l - a[n-1] > ans) ans = l - a[n-1];
	cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

