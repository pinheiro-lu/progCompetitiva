#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

multiset<int> s;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
	}

	for (int i = 0; i < q; ++i) {
		int x;
		cin >> x;
		auto it = s.lower_bound(x);
		if (it == s.end()) {
			cout << "-1\n";
		} else {
			cout << *it << '\n';
			s.erase(it);
		}
	}

	return 0;
}
