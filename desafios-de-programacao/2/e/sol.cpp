#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
<<<<<<< HEAD
=======

>>>>>>> 7eea9b23862c83cee96cbb50bba68ddead668657
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
<<<<<<< HEAD
		for (int i = 0; i < s.size()-1; i++) {
			if (s.at(i+1)-1 > s.at(i)) {
				swap(s.at(i+1), s.at(i));
				s.at(i)--;
=======
		for (int i = 1; i < s.size(); ++i) {
			for (int j = i-1; j >= 0 && s.at(j) < s.at(j+1)-1; --j) {
				swap(s.at(j+1), s.at(j));
				s.at(j)--;
>>>>>>> 7eea9b23862c83cee96cbb50bba68ddead668657
			}
		}
		cout << s << '\n';
	}
<<<<<<< HEAD



=======
>>>>>>> 7eea9b23862c83cee96cbb50bba68ddead668657
	return 0;
}
