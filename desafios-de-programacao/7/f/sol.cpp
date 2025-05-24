#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

const int N = 2e5;

array<int, N> a;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt; cin >> tt;

    while (tt--) {
        int n;
        ll x, y;
        cin >> n >> x >> y;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.begin() + n);

        ll ans = 0;
        ll L = sum - y;
        ll R = sum - x;

        for (int i = 0, j1 = n-1, j2 = n-1; i < n; ++i) {
            j1 = max(j1, i);
            j2 = max(j2, i);

            while (j1 > i && a[i] + a[j1] >= L) {
                --j1;
            }
            while (j2 > i && a[i] + a[j2] > R) {
                --j2;
            }

            ans += j2 - j1;
        }
        cout << ans << '\n';
    }
    return 0;
}

