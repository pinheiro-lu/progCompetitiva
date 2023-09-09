#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) printf(args)
#define endl '\n'

typedef long long ll;

#define MAX 100000009

void solve(void) {
	int n; cin >> n;
	int qtd = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		qtd += __builtin_ctz(x);
	}
	int op = 0;
	int max = (31 - __builtin_clz(n));
	int at = max;

	while (qtd < n && at) {
		for (int i = 1 << at; i <= n; i += 1 << at) {
			if (__builtin_ctz(i) > at) continue;
//			cout << "i, at\n";
//			cout << i << ' ' << at << '\n';
			qtd += at;
			++op;
			if (qtd >= n) {
				cout << op << '\n';
				return;
			}
		}
		--at;
	}

	if (qtd >= n) cout << op << '\n';
	else cout << "-1\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
 
	cin >> t;
	
	while (t--)
		solve();
		
	return 0;
}
