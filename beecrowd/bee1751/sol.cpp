#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, f;

vector<vector<pair<int, int>>>adj;
vector<bool> fri;
vector<int> p;
vector<bool> imp;
vector<int> dp;

int calc(int idx, int pai) {
	int s = 0;
	p.at(idx) = pai;
	//cerr << "meu pai " << pai << " e eu " << idx << '\n';
	if (adj.at(idx).size() == 1 && pai != -1) return fri.at(idx) ? 0 : -1;
	int qtd = 0;
	for (auto &[b, c] : adj.at(idx)) {
		if (b == pai) continue;
		int part = calc(b, idx);
		if (part >= 0) {
			//cerr << "idx " << idx << " somando " << b << '\n';
			s += part + c;
			++qtd;
		} else {
			//cerr << "idx " << idx << " nao somando " << b << " porque part=" << part << '\n';
		}
	}
	/*
	if (qtd >= 2) {
		imp.at(idx) = true;
	}
	*/
	//cerr << "sou " << idx << " e tenho " << s << '\n';
	if (s) {
		return s;
	} else return  fri.at(idx) ? 0 : -1;
}

int small_edge(int idx) {
	if (dp.at(idx) != -1) return dp.at(idx);
	if (imp.at(idx) || p.at(idx) == -1) return dp.at(idx) = 0;
	int s = 0;
	//cerr << "idx " << idx << " p[idx] " << p.at(idx) << '\n';
	for (auto &[b, c] : adj.at(idx)) {
		if (b == p.at(idx)) {
			s+= c;
			break;
		}
	}
	return dp.at(idx) = s + small_edge(p.at(idx));
}


void solve() {
	cin >> n >> f;

	adj.resize(n);
	fri.resize(n);
	p.resize(n);
	imp.resize(n);
	dp.assign(n, -1);

	for (int i = 0; i < n-1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		adj.at(a).push_back({b, c});
		adj.at(b).push_back({a, c});
	}

	for (int i = 0; i < f; ++i) {
		int x;
		cin >> x;
		--x;
		fri.at(x) = true;
	}

	int ans = calc(0, -1);
	int s = 0;
	for (int i = 0; i < n; ++i) {
		if (fri.at(i)) {
			s = max(s, small_edge(i));
		}
	}
	//cerr << "ans " << ans << " s " << s << '\n';

	cout << ans -s << '\n';

	

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	while (t--) solve();

	return 0;
}
