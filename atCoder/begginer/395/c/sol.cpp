#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int INF = 1e9;
const int M = 1e6+1;

vector<pair<int, int>> a(M, {-1, -1});
vector<int> b(M, INF);

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.at(x).f = a.at(x).s;
		a.at(x).s = i;
		if (a.at(x).f != -1) b.at(x) = min(b.at(x), a.at(x).s - a.at(x).f + 1);
	}
	int ans = INF;
	for (int i = 1; i < M; ++i) {
		ans = min(ans, b.at(i));
	}

	if (ans == INF) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
