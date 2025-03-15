#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int x, y;
	cin >> x;
	cin.ignore();
	cin >> y;
	int t = x*10+y;
	if (t >= 380) {
		cout << "1\n";
	} else if (t >= 375) {
		cout << "2\n";
	} else {
		cout << "3\n";
	}

	return 0;
}
