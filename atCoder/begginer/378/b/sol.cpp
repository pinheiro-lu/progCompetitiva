#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi q, r, t, d;
int n, Q;


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	q.resize(n);
	r.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> q.at(i) >> r.at(i);
	}
	cin >> Q;
	t.resize(Q);
	d.resize(Q);
	for (int i = 0; i < Q; i++) {
		cin >> t.at(i) >> d.at(i);
		--t.at(i);
		int miss = r.at(t.at(i)) - (d.at(i) % q.at(t.at(i)));
		if (miss < 0) {
			miss = r.at(t.at(i)) + q.at(t.at(i)) - (d.at(i) % q.at(t.at(i)));
		}
		cerr << "miss " << miss << '\n';
		cout << d.at(i) + miss << '\n';
	}




	return 0;
}
