#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(atoi(argv[1]));

	int n = 1 + rand() % 5;
	int k = 1 + rand() % n;
	cout << n << ' ' << k << '\n';
	for (int i = 0; i < n; ++i) {
		int x1 = rand() % 7;
		int y1 = rand() % 7;
		int x2 = 1 + x1 + (rand() % (8-x1));
		int y2 = 1 + y1 + (rand() % (8-y1));
		cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	}

	return 0;
}
