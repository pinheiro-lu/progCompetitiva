#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector <int> v, u;

bool sorted(int j) {
	for (int i = 0; i < v.size(); ++i) {
		if (i != j) {
			u.push_back(v[i]);
		}
	}
	if (is_sorted(u.begin(), u.end())) {
		return true;
	}
	return false;
}

void solve() {
	cin >> n;

	int ant = 0;

	for (int i = 0; i < n; ++i) {
		int atual;
		cin >> atual;
		if (ant != atual) {
			v.push_back(atual);
		}
		ant = atual;
	}

	int i;
	for (i = 0; i < v.size(); ++i) {
		u.clear();
		if (sorted(i)) {
			break;
		}
	}

	int j;
	for (j = 0; j < u.size()-1; ++j) {
		if (u[j] <= v[i] && v[i] <= u[j+1]) {
			break;
		}
	}

	if (is_sorted(v.begin(), v.end())) {
		cout << "0\n";
	} else	if (j < i) {
		if (v[i] == u[j+1]) {
			j++;
		}
		cout << i-j-1 << '\n';
	} else {
		cout << j-i+1 << '\n';
	}
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;

	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

	while (t--) solve();

	return 0;
}
