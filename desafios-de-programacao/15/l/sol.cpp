#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int MX = 1e7+1;

array<bool, MX> composite;
vi primes;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	// Sieve of Eratosthenes to find all primes up to MX
	for (int i = 2; i * i < MX; ++i) {
		if (!composite[i]) {
			for (int j = i * i; j < MX; j += i) {
				composite[j] = true;
			}
		}
	}
	for (int i = 2; i < MX; ++i) {
		if (!composite[i]) {
			primes.push_back(i);
		}
	}

	while (tt--) {
		ll n; cin >> n;
		bool prime = false;
		while (!prime) {
			++n;
			prime = true;
			for (int p : primes) {
				if (1LL*p * p > n) break;
				if (n % p == 0) {
					prime = false;
					break;
				}
			}
		}
		cout << n << '\n';
	}


	return 0;
}
