#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int comp (const pair<int, double>& l, const pair<int, double>& r) {
	return l.second > r.second;
}

void solve() {
	int n;

	cin >> n;

	vector<pair<int, double>>p(n);

	for (int i = 0; i < n; i++) {
		double a, b;
		cin >> a >> b;
		p[i] = make_pair(i, a/(a+b));
		//cout << p[i].first << '\n';
	}

	sort(p.begin(), p.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << p[i].first + 1<< ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

//	cin >> t;
	while (t--) solve();

	return 0;
}

