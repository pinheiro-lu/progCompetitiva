#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;

	cin >> n;

	vector<int> k(n);
	vector<vector<int>>b(n);
	set<int> s;

	for (int i = 0; i < n; i++) {
		cin >> k[i];
		b[i].resize(k[i]);
		for (int j = 0; j < k[i]; j++) {
			cin >> b[i][j];
			s.insert(b[i][j]);
		}
	}

	int spl = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k[i]-1; j++) {
			auto x = s.find(b[i][j]);
			auto nx = next(x);
			if (*nx != b[i][j+1]) {
				spl++;
			}
		}
	}

	cout << spl << ' ' << spl + n - 1;

	return 0;
}
