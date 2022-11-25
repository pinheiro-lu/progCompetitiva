#include <bits/stdc++.h>
using namespace std;

#define dbg(args...) //printf(args)
#define endl '\n'

typedef long long ll;

void solve(void) {
	ll n, sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
    }

    cout << abs(sum) << endl;
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
