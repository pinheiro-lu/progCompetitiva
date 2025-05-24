#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;

	int cnt_a = 0, cnt_b = 0;
	int ans = 0;

	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n) {
			if (s[j] == 'a') {
				cnt_a++;
			} else {
				cnt_b++;
			}
			if (min(cnt_a, cnt_b) > k) {
				cnt_a -= (s[j] == 'a');
				cnt_b -= (s[j] == 'b');
				break;
			}
			j++;
		}
		ans = max(ans, j-i);
		if (s[i] == 'a') {
			cnt_a--;
		} else {
			cnt_b--;
		}
	}
	cout << ans << '\n';

	return 0;
}
