#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve (){
	int n, s1, s2;
	
	cin >> n >> s1 >> s2;

	pair<int, int> r[n];

	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		r[i] = make_pair(x, i);
	}

	sort (r, r + n);
	reverse(r, r+n);

	int t1 = s1, t2 = s2;
	vector <int> v1, v2;

	for (int i = 0; i < n; ++i) {
		if (t1 < t2) {
			v1.push_back(r[i].second + 1);
			t1+=s1;
		} else {
			v2.push_back(r[i].second + 1);
			t2+=s2;
		}
	}

	cout << v1.size() << ' ';

	for (int x : v1) {
		cout << x << ' ';
	}
	cout << '\n';

	cout << v2.size() << ' ';

	for (int x : v2) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	int t;

	cin >> t;
	while (t--) solve();

	return 0;
}
