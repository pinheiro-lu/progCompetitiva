#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int k, n, m;

const int N = 100;

array<tuple<int, int, int>, N> chec;
array<int, N> expected;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> k >> n >> m;

	for (int i = 0; i < n; ++i) {
		chec.at(i) = {i, 0, 0};
	}

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		if (expected.at(x) == y) {
			expected.at(x) = (expected.at(x) + 1) % k;
			chec.at(x) = {x, get<1>(chec.at(x))+1, i};
		}
	}

	sort(chec.begin(), chec.begin() + n, [](tuple<int, int, int> &l, tuple<int, int, int> &r) {
			if (get<1>(l) == get<1>(r)) return get<2>(l) < get<2>(r);
			return get<1>(l) > get<1>(r);
			});

	for (int i = 0; i < n; ++i) {
		cout << get<0>(chec.at(i)) + 1 << ' ';
	}


	return 0;
}
