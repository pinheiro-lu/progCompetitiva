#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--){
		int l, r;
		cin >> l >> r;
		int mx = -1;
		int ans;
		for (int i = l; i <= r; i++) {
			int x, j = 0, mxd=0,mnd=9;
			while (x = i/(int)pow(10,j)) {
				x -= i/(int)pow(10,j+1)*10;
				//cout << "x = " << x << '\n';
				mxd=max(x,mxd);
				mnd=min(x,mnd);
				j++;
			}
			if(mxd-mnd == 9) {
				ans = i;
				break;
			}
			if (mxd-mnd > mx) {
				mx = mxd-mnd;
				ans = i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}	

