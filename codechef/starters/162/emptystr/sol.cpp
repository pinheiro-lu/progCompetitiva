#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--){
		int n;
		string s;
		cin >> n >> s;
		int expa = 0, expb = 0;
		int ans = 0;
		for (char c : s) {
			if (c == 'A') {
				expb++;
				if (expa) {
					expa--;
				} else {
					++ans;
				}
			} else {
				expa++;
				if (expb) {
					expb--;
				} else {
					++ans;
				}
			}
		}

		cout << ans << '\n';
	}



	return 0;
}
