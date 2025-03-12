#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

array<array<char, N>, N> w;
array<array<int, N/2>, N/2> cnt;

signed main() {
	int n, u;
	cin >> n >> u;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> w.at(i).at(j);
		}
	}

	for (int i = 0; i < n/2; ++i) {
		for (int j = 0; j < n/2; ++j) {
			cnt.at(i).at(j) = (w.at(i).at(j) == '#') + 
				(w.at(n-1-i).at(j) == '#') +
				(w.at(i).at(n-1-j) == '#') +
				(w.at(n-1-i).at(n-1-j) == '#');
		}
	}

	int ans = 0;

	for (int i = 0; i < n/2; ++i) {
		for (int j = 0; j < n/2; ++j) {
			ans += min(cnt.at(i).at(j), 4-cnt.at(i).at(j));
		}
	}

	cout << ans << '\n';

	for (int i = 0; i < u; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		if (w.at(a).at(b) == '#') w.at(a).at(b) = '.';
		else w.at(a).at(b) = '#';
		if (a > n/2-1) a = n-1-a;
		if (b > n/2-1) b = n-1-b;
		int aux = min(cnt.at(a).at(b), 4-cnt.at(a).at(b));
		cnt.at(a).at(b) = (w.at(a).at(b) == '#') + 
			(w.at(n-1-a).at(b) == '#') +
			(w.at(a).at(n-1-b) == '#') +
			(w.at(n-1-a).at(n-1-b) == '#');
		int aux2 = min(cnt.at(a).at(b), 4-cnt.at(a).at(b));
		ans += aux2 - aux;
		cout << ans << '\n';
	}




	return 0;
}
