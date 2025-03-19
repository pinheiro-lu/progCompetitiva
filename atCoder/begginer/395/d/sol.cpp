#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, q;
	cin >> n >> q;
	vi pig(n);
	vector<set<int>> nest(n);
	for (int i = 0; i < n; i++) {
		pig[i] = i;
		nest[i].insert(i);
	}

	while (q--) {
		int t, a;
		cin >> t >> a;
		a--;
		if (t == 3) {
			cout << pig.at(a) + 1 << '\n';
			break;
		}
		int b;
		cin >> b;
		b--;
		if (t == 1) {
			nest.at(pig.at(a)).remove(a);
			nest.at(b).insert(a);
			pig.at(a) = b;
			break;
		}



		

	return 0;
}
