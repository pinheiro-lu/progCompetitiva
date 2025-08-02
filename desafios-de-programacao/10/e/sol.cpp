#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

typedef long long ll;
typedef vector<int> vi;

const int N = 1000;

array<tuple<ll,ll,ll>, N> fences; // (r, x, y)
array<pair<ll,ll>, N> pts;
array<int, N> cp_list;
array<int, N> cp_depth;
vector<vi> lists;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> pts[i].f >> pts[i].s;
        cp_list[i] = -1;
    }

    for (int i = 0; i < m; ++i) {
        ll r, x, y;
        cin >> r >> x >> y;
        fences[i] = {r, x, y};
    }

    sort(fences.begin(), fences.begin() + m);
    reverse(fences.begin(), fences.begin() + m);

    for (int id = 0; id < m; ++id) {
        bool placed = false;
        for (auto &lst : lists) {
            int top = lst[0];
            ll dx = get<1>(fences[id]) - get<1>(fences[top]);
            ll dy = get<2>(fences[id]) - get<2>(fences[top]);
            ll rt = get<0>(fences[top]);
            if (dx*dx + dy*dy <= rt * rt) {
                lst.push_back(id);
                placed = true;
                break;
            }
        }
        if (!placed) lists.push_back({ id });
    }

    for (int i = 0; i < n; ++i) {
        ll px = pts[i].f, py = pts[i].s;
        for (int j = 0; j < (int)lists.size(); ++j) {
            int top = lists[j][0];
            ll dx0 = px - get<1>(fences[top]);
            ll dy0 = py - get<2>(fences[top]);
            ll rt = get<0>(fences[top]);
            if (dx0*dx0 + dy0*dy0 <= rt * rt) {
                for (int d = 0; d < (int)lists[j].size(); ++d) {
                    int fid = lists[j][d];
                    ll dx1 = px - get<1>(fences[fid]);
                    ll dy1 = py - get<2>(fences[fid]);
                    ll rf = get<0>(fences[fid]);
                    if (dx1*dx1 + dy1*dy1 <= rf * rf) {
                        cp_list[i] = j;
                        cp_depth[i] = d + 1;
                    } else break;
                }
                break;
            }
        }
    }

    while (k--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        int la = cp_list[a], lb = cp_list[b];
        int da = cp_depth[a], db = cp_depth[b];
        int ans = (la != -1 && la == lb) ? abs(da - db) : da + db;
        cout << ans << '\n';
    }

    return 0;
}

