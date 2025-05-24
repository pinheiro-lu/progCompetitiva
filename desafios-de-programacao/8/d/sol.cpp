#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 500;
array<array<bool, N>, N> adj;
array<char, N> ans;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a][b] = adj[b][a] = true;
	}

	for (int i = 0; i < n; ++i) {
		adj[i][i] = true;
		for (int j = 0; j < n; ++j) {
			if (!adj[i][j]) {
				for (int k = 0; k < n; ++k) {
					if (!adj[k][j]) {
						ans[k] = 'a';
					} else if (!adj[i][k]) {
						ans[k] = 'c';
					} else {
						ans[k] = 'b';
					}
				}
			}
		}
	}

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            bool should = abs(ans[i] - ans[j]) <= 1;
            if (should != adj[i][j]) {
                cout << "No\n";
                return 0;
            }
        }
    }


	cout << "Yes\n";
	for (int i = 0; i < n; ++i) {
		if (!ans[i]) {
			ans[i] = 'a';
		}
		cout << ans[i];
	}

	return 0;
}
