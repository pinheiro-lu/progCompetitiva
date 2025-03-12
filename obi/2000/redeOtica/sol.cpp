#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int MAXN = 100;

vector<tuple<int, int, int>> adj;
vector<vector<bool>> new_adj;

int n, m;

bool dfs(int s, int d, int pai) {
	bool ans = false;
	if (s == d) return true;
	for (int i = 0; i < n; ++i) {
		if (i == pai) continue;
		if (new_adj.at(s).at(i)) ans |= dfs(i, d, s);
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt = 1;
	while (true) {
		cin >> n >> m;
		if (n == 0) break;
		adj.clear();
		new_adj.assign(n, vector<bool>(n, false));

		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			--a, --b;
			adj.push_back({c, a, b});
			adj.push_back({c, b, a});
		}

		sort(adj.begin(), adj.end());


		for (int i = 0; i < 2*m; ++i) {
			if (!dfs(get<1>(adj.at(i)),get<2>(adj.at(i)), -1)){
				new_adj.at(get<1>(adj.at(i))).at(get<2>(adj.at(i))) = true;
				new_adj.at(get<2>(adj.at(i))).at(get<1>(adj.at(i))) = true;
			}
		}

		cout << "Teste " << cnt++ << '\n';
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				if (new_adj.at(i).at(j)) cout << i+1 << ' ' << j+1 << '\n';
			}
		}
		cout << '\n';

	}



	return 0;
}
