#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second
/*
vi primes;

vector<long long> trial_division4(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
*/
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll y; cin >> y;
	ll k; cin >> k;
	ll x = 1;
	/*int n = y;
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i] && (long long)i * i <= n) {
			primes.push_back(i);
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}

	vector<ll> factors = trial_division4(y);
*/
	ll t = y;
	vector<ll> factors;
	for (ll i = 2; i*i <= t; ++i) {
		while (t % i == 0) {
			t /= i;
			factors.push_back(i);
		}
	}
	if (t > 1) {
		factors.push_back(t);
	}
	int i = 0;
	while (k > 0 && x < y && i < factors.size()) {
		 k -= factors[i] - 1;
		 x *= factors[i];
		 if (k < 0) {
			 x -= -k*factors[i];
			 k = 0;
		 }
		 ++i;
	}
	x += k*x;

	cout << x << '\n';

	return 0;
}
