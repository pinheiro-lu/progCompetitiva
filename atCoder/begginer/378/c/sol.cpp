#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int n;
vi a;
map<int, int> mp;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a.at(i);
		cout << ((mp.count(a.at(i))) ? mp.at(a.at(i)) + 1 : -1) << ' ';
		mp.insert_or_assign(a.at(i), i);
	}




	return 0;
}
