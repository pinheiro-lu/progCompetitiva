#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int ant = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x <= ant) {
			cout <<"NO\n";
			return 0;
		}
		ant = x;
	}
	cout << "YES\n";

	return 0;
}
