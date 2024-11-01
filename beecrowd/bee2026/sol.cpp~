#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int p, w;
vector<int> weight, enf;

int dp(int id, int rem_w) {
	if (id == p || rem_w == 0) return 0;
	if (rem_w < weight.at(id)) return dp(id+1, rem_w);
	return max(enf.at(id) + dp(id+1, rem_w-weight.at(id)), dp(id+1, rem_w));
}

void solve() {
	cin >> p >> w;

	weight.resize(p);
	enf.resize(p);
	
	for (int i = 0; i < p; ++i) {
		cin >> enf.at(i) >> weight.at(i);
	}

	cout << dp(0, w) << '\n';


}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Galho " << i << ":\nNumero total de enfeites: ";
		solve();
		cout << '\n';
	}

	return 0;
}
