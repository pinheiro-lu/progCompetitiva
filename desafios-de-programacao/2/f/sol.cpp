#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5 + 5;
array<int, N> a;
multiset<int> s, ans;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		s.clear();
		ans.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			s.insert(a[i]);
		}
		for (int i = 0; i < n; ++i) {
			s.erase(s.find(a[i]));
			if (!s.empty() && *s.begin() < a.at(i)) {
				ans.insert(a.at(i)+1);
				s.insert(a.at(i)+1);
			} else {
				ans.insert(a.at(i));
			}
		}
		for (int x : ans) {
			cout << x << ' ';
		}
		cout << '\n';
	}


	return 0;
}
