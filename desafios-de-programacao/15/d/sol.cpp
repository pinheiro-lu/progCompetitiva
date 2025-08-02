#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int a = 0, b = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			char c;
			cin >> c;
			if (c == '-') ++a;
			else ++b;
		}
		cout << (a*1LL/2*((a+1)/2)*b) << '\n';
	}

	return 0;
}
