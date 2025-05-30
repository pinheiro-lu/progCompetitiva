#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

int e, l;

vector<bool>visited;
vector<vector<bool>> adj;

void dfs(int idx) {
	if (visited.at(idx)) return;
	visited.at(idx) = true;
	for (int i = 0; i < e; ++i) {
		if (adj.at(idx).at(i)) dfs(i);
	}
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt = 1;
	while (true) {
		cin >> e >> l;
		if (!e) break;
		visited.assign(e, false);
		adj.assign(e, vector<bool>(e));

		for (int i = 0; i < l; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			adj.at(x).at(y) = true;
			adj.at(y).at(x) = true;
		}

		dfs(0);

		bool ans = true;
		for (int i = 0; i < e; ++i) {
			if (!visited.at(i)) ans = false;
		}

		cout << "Teste " << cnt++ << '\n';
		cout << (ans ? "normal" : "falha") << "\n\n";
	}


	return 0;
}
