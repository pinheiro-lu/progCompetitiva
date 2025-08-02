#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 1e5;
array<int, N> par;
array<ll, N> sum;
array<set<int>, N> sets;
int n, m;

void move(int el, int dest) {
	sets[par[el]].erase(el); // remove from current set
	sum[par[el]] -= (el + 1); // subtract value from sum
	par[el] = par[dest]; // update parent to destination's parent
	sets[par[el]].insert(el); // add to new set
	sum[par[el]] += (el + 1); // add value to new sum
}

void unite(int a, int b) {
	if (par[a] == par[b]) return; // already in the same set
	if (sets[par[a]].size() < sets[par[b]].size()) swap(a, b); // union by size
	sum[par[a]] += sum[par[b]];
	int tmp = par[b];
	for (int x : sets[tmp]) {
		par[x] = par[a]; // update parent for all elements in b's set
	}
	sets[par[a]].insert(sets[tmp].begin(), sets[tmp].end());
	sets[tmp].clear();
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> n >> m) {
		for (int i = 0; i < n;++i) {
			par[i] = i;
			sum[i] = i+1;
			sets[i].clear();
			sets[i].insert(i);
		}
		while (m--) {
			int tp, p;
			cin >> tp >> p;
			--p;
			if (tp == 3) {
				cout << sets[par[p]].size() << ' ' << sum[par[p]] << '\n';
				continue;
			}
			int q;
			cin >> q;
			--q;
			if (tp == 1) {
				unite(p, q);
			} else {
				move(p, q);
			}
		}
	}

	return 0;
}
