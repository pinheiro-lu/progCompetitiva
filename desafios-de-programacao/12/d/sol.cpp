#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 2e5+1;

array<bool, N> in, out;
array<vi, 2*N> changes;
array<int, 2*N> actual;
array<pair<int, int>, N> range;
array<pair<int, int>, 2*N> aux;

map<int, set<int>> act;
int n, x, y;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		range[i] = {x, y};
		aux[2*i-1] = {x, i};
		aux[2*i-2] = {y, -i};
	}

	sort(aux.begin(), aux.begin() + 2*n);

	for (int i = 0; i < 2*n; ++i) {
		changes[lower_bound(aux.begin(), aux.begin() + 2*n, make_pair(aux[i].f, -n)) - aux.begin()].push_back(aux[i].s);
		actual[i] = aux[i].f;
	}

	for (int t = 0; t < 2*n; ++t) {
		auto &v = changes[t];
		vi to_rem;
		for (int i : v) {
			if (i > 0) {
				act[actual[t]].insert(i);
			} else {
				i = -i;
				if (act[range[i].f].size() > 1 || act.find(range[i].f) != act.begin()) {
					in[i] = true;
				}
				to_rem.push_back(i);
			}
		}
		for (int i : to_rem) {
			act[range[i].f].erase(i);
			if (act[range[i].f].empty()) {
				act.erase(range[i].f);
			}
		}
	}
	for (int t = 0; t < 2*n; ++t) {
		auto &v = changes[t];
		vi to_rem;
		for (int i : v) {
			if (i > 0) {
				act[actual[t]].insert(i);
			} else {
				i = -i;
				// add to out the other ranges that started with me
				for (int j : act[range[i].f]) {
					if (j != i) {
						out[j] = true;
						to_rem.push_back(j);
					}
				}
				// add to out the ranges that started before me
				for (auto it = act.begin(); it != act.end() && it->first < range[i].f; ++it) {
					for (int j : it->s) {
						out[j] = true;
						to_rem.push_back(j);
					}
				}
				to_rem.push_back(i);
			}
		}
		for (int i : to_rem) {
			act[range[i].f].erase(i);
			if (act[range[i].f].empty()) {
				act.erase(range[i].f);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << out[i] << " ";
	}
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		cout << in[i] << " ";
	}

	return 0;
}
