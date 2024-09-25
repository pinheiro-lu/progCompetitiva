#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll apple[20];
ll total;
ll sum;
ll min_diff;


void rec (int tam, int st) {
	cout << "tam " << tam << " st " << st << " sum " << sum << " min_diff " << min_diff << '\n';
	if (tam == 1) {
		sum += apple[st];
		min_diff = min(min_diff, abs(sum - (total-sum)));
		sum -= apple[st];
		return;
	}
	for (int i = st; i <= n-tam; ++i) {
		sum += apple[i];
		rec(tam-1, i+1);
		sum -= apple[i];
	}
}



void solve() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> apple[i];
		total += apple[i];
	}
	min_diff = total;

	for (int i = 1; i < n; ++i) {
		for (int ap = 0; ap <= n-i; ++ap) {
			rec(i, ap);
		}
	}
	
	cout << min_diff << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
