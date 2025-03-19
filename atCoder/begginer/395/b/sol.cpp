
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 50;

array<array<char, N>, N> a;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int j = n - i - 1;
		if (i > j) break;
		for (int k = i; k <= j; ++k) {
			for (int l = i; l <= j; ++l) {
				if (i % 2 == 0) a.at(k).at(l) = '#';
				else a.at(k).at(l) = '.';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; ++j) {
			cout << a.at(i).at(j);
		}
		cout << '\n';
	}



	return 0;
}
