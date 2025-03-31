#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<bool> primes(n+1);
	for (int i = 2; i <= n; ++i) {
		if (primes.at(i)) continue;
		for (int j = i+i; j <= n; j += i) {
			primes.at(j) = true;
		}
	}

	int ans = 0;
	for (int i = 2; i <= n; ++i) {
		int cnt = 0;
		for (int j = 2; j < i; ++j) {
			if (!primes.at(j) && i%j == 0) {
				++cnt;
			}
		}
		if (cnt == 2) {
			++ans;
		}
	}
	cout << ans << '\n';

	return 0;
}
