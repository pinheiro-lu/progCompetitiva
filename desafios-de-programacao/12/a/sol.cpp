#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 2e5;

int n;

array<pair<int, int>, N> mov;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> mov[i].s >> mov[i].f;
	}

	int lst_f = 0;
	int ans = 0;

	sort(mov.begin(), mov.begin() + n);

	for (int i = 0; i < n; ++i) {
		if (mov[i].s >= lst_f) {
			lst_f = mov[i].f;
			++ans;
		}
	}

	cout << ans << '\n';

	return 0;
}
