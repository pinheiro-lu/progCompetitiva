#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 20;

array<array<ll, 1<<N>, N> dp;
array<array<int, N>, N> adj;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1][v - 1]++;
    }

    dp[0][1] = 1;

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1 << u)) || !dp[u][mask]) continue;

            for (int v = 0; v < n; ++v) {
				if (!(mask & (1 << v)) && adj[u][v]) {
                    dp[v][mask | (1 << v)] += dp[u][mask] * adj[u][v];
					dp[v][mask | (1 << v)] %= MOD;
                }
            }
        }
    }

    cout << dp[n - 1][(1 << n) - 1] << '\n';
    return 0;
}

