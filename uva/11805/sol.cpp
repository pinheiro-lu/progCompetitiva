#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k, p;

	cin >> n >> k >> p;
	if ((k+p) % n == 0) { cout << n << '\n'; return;}
	cout << (k + p) % n << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	for (int i = 0; i < t; i++) {cout << "Case " << i+1 << ": "; solve();}

	return 0;
}

