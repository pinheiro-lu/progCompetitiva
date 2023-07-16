#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5+3;

vector<multiset<int>>v(N);
vector<set<int>>c(N);

void solve() {
	int n, q;

	cin >> n >> q;
	n++;
	
	while (q--) {
		int a, i;

		cin >> a >> i;

		if (a == 1) {
			int j;
			cin >> j;
			v[j].insert(i);
			c[i].insert(j);
		}
		else if (a == 2) {
			for (int x : v[i]) {
				cout << x << ' ';
			}
			cout << '\n';
		}
		else {
			for (int x : c[i]) {
				cout << x << ' ';
			}
			cout << '\n';
		}
	}


}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

