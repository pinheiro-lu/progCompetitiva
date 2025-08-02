#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int M = 100;

array<int, M> a;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		for (int j = l; j <= r; j++) {
			a[j]++;
		}
	}
	set<int> s;

	for (int i = 0; i < m; i++) {
		if (a[i] == 0) {
			s.insert(i+1);
		}
	}

	cout << s.size() << '\n';
	for (auto x : s) {
		cout << x << ' ';
	}

	return 0;
}
