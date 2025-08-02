#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	set<int> p;
	multiset<int> tam;

	int x, n;
	cin >> x >> n;
	p.insert(0);
	p.insert(x);
	tam.insert(x);
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;

		auto it = p.lower_bound(m);
		it--;
		int l = *it;
		it = p.upper_bound(m);
		int r = *it;
		p.insert(m);
		tam.erase(tam.find(r - l));
		tam.insert(m - l);
		tam.insert(r - m);
		cout << *tam.rbegin() << " ";
	}

	return 0;
}
