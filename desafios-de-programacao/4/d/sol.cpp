#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e6 + 1;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	vector<bool> criba(N);
	set<int> primes;
	for (int i = 2; i < N; i++) {
		if (!criba[i]) {
			primes.push_back(i);
			for (int j = i; j < N; j += i) {
				criba[j] = true;
			}
		}
	}
	cerr << primes.size() << '\n';

	vector<int> ans(N);

	for (int i = 2; i < N; ++i) {
		int aux = 1;
		int x = i;
		//cerr << x << '\n';
		for (int p : primes) {
			if (p*p > x) break;
			int cnt = 0;
			while (x % p == 0) {
				x /= p;
				cnt++;
			}
			//cerr << p << ' ' << cnt << '\n';
			aux *= (cnt + 1);
		}
		ans.at(i) = aux;
	}
	ans.at(1) = 1;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x != 1 && ans.at(x) == 1) ans.at(x) = 2;
		cout << ans.at(x) << '\n';
	}

	return 0;
}
