#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int arr[13] = {0};
		if (a > b) swap(a, b);
		arr[c] = arr[d] = 1;
		int sum = 0;
		for (int i = a; i <= b; ++i) {
			sum += arr[i];
		}
		if (sum == 1) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}

	return 0;
}
