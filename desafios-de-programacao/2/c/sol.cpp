#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

priority_queue<int> pq;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	ll s, sum = 0;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		sum += x;
		pq.push(x);
	}

	int tm = 0;
	while (sum > s) {
		++tm;
		int rm = pq.top();
		sum -= rm-rm/2;
		pq.pop();
		pq.push(rm/2);
	}

	cout << tm << '\n';

	return 0;
}
