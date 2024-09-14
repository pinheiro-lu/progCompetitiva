#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
map<string, vector<string>> mp;

void dfs (string cow, vector<string>& dq) {
	cerr << "dfs " << cow << " size " << mp[cow].size() << endl;
	if (mp[cow].size() == 0) return;
	string adj = mp[cow][0];
	cerr << "adj " << adj << endl;
	dq.push_back(adj);
	mp[cow].erase(find(mp[cow].begin(), mp[cow].end(), adj));
	mp[adj].erase(find(mp[adj].begin(), mp[adj].end(), cow));
	dfs(adj, dq);
}


void solve() {
	cin >> n;

	mp["Bessie"] = vector<string>();
	mp["Buttercup"] = vector<string>();
	mp["Belinda"] = vector<string>();
	mp["Beatrice"] = vector<string>();
	mp["Bella"] = vector<string>();
	mp["Blue"] = vector<string>();
	mp["Betsy"] = vector<string>();
	mp["Sue"] = vector<string>();

	for (int i = 0; i < n; ++i) {
		string a, b, x;
		cin >> a >> x >> x >> x >> x >> b;
		if (find(mp[a].begin(), mp[a].end(), b) == mp[a].end()) {
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
	}
	cerr << "done reading" << endl;

	vector<vector<string>> ans;

	for (auto& [cow, v] : mp) {
		bool used = false;
		cerr << "adding " << cow << endl;
		for (auto& used_cows : ans) {
			if (find(used_cows.begin(), used_cows.end(), cow) != used_cows.end()) {
				used = true;
			}
		}
		if (used) continue;
		cerr << "not used" << endl;

		vector<string> dq;
		dq.push_back(cow);
		dfs(cow, dq);
		if (mp[cow].size()) {
			reverse(dq.begin(), dq.end());
			dfs(cow, dq);
		}
		cerr << "done dfs " << cow << endl;
		if (dq.back() < dq.front()) {
			reverse(dq.begin(), dq.end());
		}
		ans.push_back(dq);
	}

	sort(ans.begin(), ans.end());

	for (auto& dq : ans) {
		for (string cow : dq) {
			cout << cow << '\n';
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

	solve();
	return 0;
}

