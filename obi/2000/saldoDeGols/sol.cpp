#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int MAXN = 1e4;

array<int, MAXN> res;
array<int, MAXN+1> pre;


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int cnt = 1;
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			res.at(i) = a-b;
		}

		partial_sum(res.begin(), res.end(), pre.begin()+1);

		int ans = 0, st = -1, ed = -2;
		for(int l = 1; l <= n; ++l) {
			for (int r = l; r <= n; ++r) {
				int aux;
				if ((aux = pre.at(r)-pre.at(l-1)) > ans) {
					ans = aux;
					st = l;
					ed = r;
				} else if (aux == ans) {
					if (r-l > ed-st) {
						ed = r, st = l;
					}
				}
			}
		}

		cout << "Teste " << cnt++ << '\n';

		if (!ans) cout << "nenhum\n\n";
		else cout << st << ' ' << ed << "\n\n";

	}



	return 0;
}
