#include <bits/stdc++.h>

using namespace std;

#define N 106

int main() {
	int n, k;

	cin >> n >> k;

	vector<vector<int>> a(N, vector<int>(N));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int q;

	cin >> q;

	vector <int> s(q), t(q);

	for (int i = 0; i < q; i++) {
		cin >> s[i] >> t[i];
	}

