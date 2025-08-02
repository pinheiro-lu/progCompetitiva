#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 2e5;
int n, m;
set<pair<int, int>> rooms;
set<pair<int, int>> sort_rooms;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		rooms.insert({i, x});
		if (x > sort_rooms.rbegin()->f) {
			sort_rooms.insert({x, i});
		}
	}

	while (m--) {
		cin >> x;

	return 0;
}
