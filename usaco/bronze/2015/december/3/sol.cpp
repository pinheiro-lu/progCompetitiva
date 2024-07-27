#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M, D, S;
vector<tuple<int, int, int>> transcript;
set <int> infected;
vector<set<int>> notdrunk;

void solve() {
	cin >> N >> M >> D >> S;

	for (int i = 0; i < D; ++i) {
		int p, m, t;
		cin >> p >> m >> t;
		transcript.push_back(make_tuple(t, m, --p));
	}

	for (int i = 0; i < S; ++i) {
		int t, p;
		cin >> p >> t;
		transcript.push_back(make_tuple(t, 0, --p));
	}

	sort(transcript.begin(), transcript.end(), [](auto l, auto r) {
			int t1 = get<0>(l);
			int t2 = get<0>(r);
			int m1 = get<1>(l);
			int m2 = get<1>(r);
			if (t1 == t2) {
				return m1 < m2;
			}
			return t1 < t2;
			});

	for (int i = 1; i <= M; ++i) {
		infected.insert(i);
	}

	for (int i = 0; i < N; ++i) {
		set<int> s;
		for (int m = 1; m <= M; ++m) {
			s.insert(m);
		}
		notdrunk.push_back(s);
	}


	for (auto & happening : transcript) {
		int t, m, p;
		tie(t, m, p) = happening;
		if (m == 0) {
			for (int n : notdrunk[p]) {
				if (infected.count(n)) {
					infected.erase(infected.find(n));
				}
			}
		} else {
			if (notdrunk[p].count(m)) {
				notdrunk[p].erase(m);
			}
		}
	}

	int bad = *(infected.begin());

	set <int> contamined;
	for (auto & happening : transcript) {
		int t, m, p;
		tie(t, m, p) = happening;

		if (m == bad) contamined.insert(p);

	}

	cout << contamined.size() << '\n';

}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	freopen("badmilk.in", "r", stdin);
	freopen("badmilk.out", "w", stdout);

	while (t--) solve();

	return 0;
}
