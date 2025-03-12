#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		vector<pair<string, set<string>>> v;
		set<string> dis;

		for (int i = 0; i < n; ++i) {
			string s0;
			int k;
			cin >> s0 >> k;
			int idx;
			if (dis.count(s0)) {
				for (idx = 0; ; ++idx) {
					if (v.at(idx).first == s0) break;
				}
			} else {
				dis.insert(s0);
				idx = v.size();
				v.push_back({s0, set<string>()});
			}
			for (int j = 0; j < k; ++j) {
				string s;
				cin >> s;
				v.at(idx).second.insert(s);
				if (!dis.count(s)) {
					dis.insert(s);
					v.push_back({s,set<string>()});
				}
			}
		}
		vector<set<string>> sem;

		int cnt = 0;
		while (cnt < v.size()) {
			set<string> mat;
			for (auto &[a, b] : v) {
				if (mat.size() == m) break;
				if (a=="") continue;
				if (b.empty()) {
					mat.insert(a);
					a = "";
					cnt++;
				}
			}
			for (string a : mat){
				for (auto &[_, c] : v) {
					c.erase(a);
				}
			}
			sem.push_back(mat);
		}

		cout << "Formatura em " << sem.size() << " semestres\n";
		for (int i = 0; i < sem.size(); ++i) {
			cout << "Semestre " << i+1 << " : ";
			for (string s : sem.at(i)) {
				cout << s << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
