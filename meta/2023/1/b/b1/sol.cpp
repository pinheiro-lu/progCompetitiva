#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int pri[] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41
};

void solve() {
	int p; cin >> p;

	vector<int> v;
	int sum = 0;

	for (int i = 0; i < 13 && pri[i] * pri[i] <= p; ++i) {
		while (!(p % pri[i])) {
			p /= pri[i];
			v.push_back(pri[i]);
			sum += pri[i];
		}
	}
	if (p != 1) {
		v.push_back(p);
		sum += p;
	}
	if (sum > 41) {
		cout << "-1\n";
		return;
	}
	sort(v.begin(), v.end());
	while (sum + v.back() * v[0] - v[0] - v.back() <= 41) {
		int i = 0, j = v.size()-1;
		sum += v.back() * v[0] - v[0] - v.back();
		v.push_back(v.back() * v[0]);
		v.erase(v.begin());
		v.erase(v.end()-1);
		sort(v.begin(), v.end());
	}

	while (sum < 41) {
		v.push_back(1);
		++sum;
	}
	if (v.size() > 100) {
		cout << "-1\n";
		return;
	}

	cout << v.size() << ' ';

	for (int x : v) {
		cout << x << ' ';
	}
	cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
