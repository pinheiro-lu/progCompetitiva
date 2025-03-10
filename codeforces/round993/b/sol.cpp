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
		string a; 
		cin >> a;
		string b{};
		for (int i = a.size()-1; i >= 0; i--) {
			if (a[i] == 'p') {
				b += 'q';
			} else if (a[i] == 'q') {
				b += 'p';
			} else b += a[i];
		}
		cout << b << '\n';
	}

	return 0;
}
