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
		string s;
		cin >> s;
		for (int i = s.size()-1; i>=0; --i) {
			cout << (s.at(i) == 'p' ? 'q' : s.at(i) == 'q'? 'p' : 'w');
		}
		cout << '\n';
	}


	return 0;
}
