#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (i == 0) {
				q.push(x);
			} else {
				if (q.front() == q.size() && x >= q.size()) {
					q.pop();
					q.push(x);
				} else if (x >= q.size()) {
					q.push(x);
				}
			}
			cout << q.size() << " ";
		}
		cout << '\n';
	}

	return 0;
}
