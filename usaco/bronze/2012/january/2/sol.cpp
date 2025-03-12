#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n, k;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("stacking.in", "r", stdin);
	//freopen("stacking.out", "w", stdout);

	cin >> n >> k;

	vi diff(n+2);

	for (int i = 1; i <= k; ++i) {
		int a, b;
		cin >> a >> b;
		diff.at(a)++;
		diff.at(b+1)--;
	}

	vi org(n);
	partial_sum(diff.begin(), diff.begin() + n+1, org.begin());

	sort(org.begin(), org.end());

	//for (int i = 0; i < n; ++i) cerr << org.at(i) << ' ';
	//cerr << '\n';

	cout << org.at(n/2) << '\n';



	return 0;
}
