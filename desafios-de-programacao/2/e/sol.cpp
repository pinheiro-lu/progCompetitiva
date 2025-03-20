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
		for (int i = 1; i < s.size(); ++i) {
			for (int j = i-1; j >= 0 && s.at(j) < s.at(j+1)-1; --j) {
				swap(s.at(j+1), s.at(j));
				s.at(j)--;
			}
		}
		cout << s << '\n';
	}
	return 0;
}
