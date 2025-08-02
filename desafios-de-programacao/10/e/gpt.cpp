#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define f first
#define s second

const int N = 1000;

pair<ll, ll> pts[N]; // control points
tuple<ll, ll, ll> fences[N]; // (r, x, y)

bool inside(ll px, ll py, ll cx, ll cy, ll r) {
    ll dx = px - cx, dy = py - cy;
    return dx * dx + dy * dy < r * r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
        cin >> pts[i].f >> pts[i].s;

    for (int i = 0; i < m; ++i) 
        cin >> get<0>(fences[i]) >> get<1>(fences[i]) >> get<2>(fences[i]);

    while (k--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            bool in_a = inside(pts[a].f, pts[a].s, get<1>(fences[i]), get<2>(fences[i]), get<0>(fences[i]));
            bool in_b = inside(pts[b].f, pts[b].s, get<1>(fences[i]), get<2>(fences[i]), get<0>(fences[i]));

            if (in_a != in_b) ++cnt;
        }
        cout << cnt << '\n';
    }
}

