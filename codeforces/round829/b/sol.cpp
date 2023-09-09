#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) //printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	int n;

    cin >> n;

	int j = n/2 + 1;
	int i = 1;

	for (int k = 0; k < n; k+=2, ++i, ++j) {
		if ( i == n/2 + 1) {
			cout << j; break;
		}
		cout << j << ' ' << i << ' ';
	}
	cout << '\n';

}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	
    cin >> t;
	//scanf("%d", &t);
//	while (getchar() != '\n');

	while (t--)
		solve();
		
	return 0;
}
