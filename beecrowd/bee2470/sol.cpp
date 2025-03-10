#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e4;

int n;
int ans;
vector<pair<int, int>>c;
vector<vector<int>> adj;
array<int, 2*MAXN-1> dep;
array<int, 2*MAXN-1> id;
array<bool, MAXN> vis;
array<int, MAXN> pos;
array<int, MAXN> nvl;
vector<array<int, 2*MAXN-1>> st;

int cnt;

void dfs(int idx, int pai, int depth) {
	//cerr << pai << " me trouxe aqui " << idx << '\n';
	if (idx == -1) return;
	pos.at(idx) = cnt;
	id.at(cnt) = idx;
	if (nvl.at(idx) == -1) nvl.at(idx) = depth;
	dep.at(cnt) = nvl.at(idx);
	if (vis.at(idx)) return;
	vis.at(idx) = true;
	for (int &x : adj.at(idx)) {
		if (x == pai) continue;
		++cnt;
		dfs(x, idx, depth+1);
	}
	++cnt;
	dfs(pai, idx, depth+1);
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	c.resize(n/2, make_pair(-1, -1));
	adj.resize(n);
	fill(vis.begin(), vis.end(), false);
	fill(nvl.begin(), nvl.end(), -1);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		if (c.at(x).first != -1) {
			c.at(x).second = i;
		} else {
			c.at(x).first = i;
		}
	}

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj.at(a).push_back(b);
		adj.at(b).push_back(a);
	}

	dfs(0, -1, 0);

	int m = 2*n-1;
	st.push_back(dep);
	for (int i = 1; (1 << i) < m; ++i) {
		st.push_back({});
		for (int j = 0; j <= m - (1 << i); ++j) {
			st.at(i).at(j) = min(st.at(i-1).at(j), st.at(i-1).at(j + (1 << (i-1))));
		}
	}
	for (auto& x : st) {
		for (int i = 0; i < 2*n-1; ++i) {
			//cerr << x.at(i) << ' ';
		}
		//cerr << '\n';
	}
	////cerr << "st done\n";
	for (int i = 0; i < 2*n-1; ++i) {
		//cerr << id.at(i) << ' ' << dep.at(i) << '\n';
	}

	int sum = 0;
	for (auto&[a, b] : c) {
		////cerr << "a " << a << " b " << b << '\n';
		int f = min(pos.at(a), pos.at(b));
		int l = max(pos.at(a), pos.at(b));
		int w = 0; while ((1 << w) <= l-f+1) ++w;
		--w;
		////cerr << "a " << a << " b " << b << '\n';
		////cerr << "w " << w << " f " << f << " l " << l << '\n';
		int lca = min(st.at(w).at(f), st.at(w).at(l+1 - (1<<w)));
		sum += nvl.at(a) + nvl.at(b) - 2*lca;
	}

	cout << sum << '\n';



	return 0;
}
