#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int MAXN = 2e5;

multimap<int, int> num, pos;
array<int, MAXN> ans;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			int a; cin >> a;
			num.insert({a>>2, a});
			pos.insert({a>>2, i});
		}

		priority_queue<int> pq;
		int key;
		auto it_num = num.begin();
		while (it_num != num.end()) {
			for (key = it_num->first; it_num != num.end() && it_num->first == key; ++it_num) {
				pq.push(-it_num->second);
			}

			auto range = pos.equal_range(key);
			for (auto it = range.first; it != range.second; ++it) {
				ans.at(it->second) = -pq.top();
				pq.pop();
			}
		}

		for (int i = 0; i < n; ++i) {
			cout << ans.at(i) << ' ';
		}
		cout << '\n';

		num.clear();
		pos.clear();


	}

	return 0;
}
