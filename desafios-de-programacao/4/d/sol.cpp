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
	vector<int> primes;
	for (int i = 2; i < N; i++) {
		if (!criba[i]) {
			primes.push_back(i);
			for (int j = i; j < N; j += i) {
				criba[j] = true;
			}
		}
	}

	vi ans(N);

	ans.at(1) = 1;

	for (int i = 2; i < N; ++i) {
		int x = i;
		int aux = 1;
		for (int p : primes) {
			if (p * p > x) break;
			int cnt = 0;
			while (x % p == 0) {
				x /= p;
				++cnt;
			}
			aux *= (cnt + 1);
		}
		if (x > 1) aux *= 2;
		ans[i] = aux;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		cout << ans[x] << '\n';
	}

	return 0;
}
