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
		for (int i = 0; i < s.size()-1; i++) {
			if (s.at(i+1)-1 > s.at(i)) {
				swap(s.at(i+1), s.at(i));
				s.at(i)--;
			}
		}
		cout << s << '\n';
	}



	return 0;
}
