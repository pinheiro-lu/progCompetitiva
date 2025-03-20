
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < s.size(); ++i) {
		if (i & 1 && s.at(i) == 'i') {
			s.insert(i, "i");
		} else if (!(i & 1) && s.at(i) == 'o') {
			s.insert(i, "o");
		}
	}
	if (s.size() & 1) {
		s.push_back('o');
	}
	cout << s.size() - n << '\n';


	return 0;
}
