#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int a;
	cin >> a;

	cout << (400 % a == 0 ? 400 / a : -1) << '\n';


	return 0;
}
